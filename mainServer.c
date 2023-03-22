#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include "main.h"
#include "data.h"
#include "select.h"
#include "add.h"

#define ARR_LEN(_arr) (sizeof(_arr) / sizeof(_arr[0]))

typedef struct
{
    int new_sock;
    char *file_name;
} Args;

void print_customer(Customers *customer, int new_sock)
{
    char buffer[MAX_LEN];

    sprintf(buffer, "\n%s %s\n %s\n %d\n %d\n %.2f\n",
            customer->first_name,
            customer->second_name,
            customer->date,
            customer->id,
            customer->phone,
            customer->debt);
    printf("%s", buffer);

    send(new_sock, buffer, strlen(buffer), 0);
}
void eroor_send(char *errors , int new_sock)
{
    send(new_sock, errors, MAX_LEN, 0);
   
}

void *conn_handler(void *args)
{
    Args *arg = (Args *)args;
    int new_sock = arg->new_sock;
    char *file_name = arg->file_name;

    int n = 0;
    const char *menu[] = {"set", "select", "print"};

    char input[MAX_LEN] = {0};
    char errors[MAX_LEN] = {0};
    char input_choise[MAX_LEN];
    char *input_to_sent;
    int i;

    BST *id_tree = NULL;
    BST *debt_tree = NULL;
    BST *date_tree = NULL;
    BST *phone_tree = NULL;
    BST *first_name_tree = NULL;
    BST *second_name_tree = NULL;
    char message[1036] = {0};

    BST *trees[] = {id_tree, debt_tree, date_tree, phone_tree, first_name_tree, second_name_tree};

    n = recv(new_sock, input, MAX_LEN, 0);

    if (n < 0)
    {

        perror("Server error receiving data");

        goto exit;
    }
    input[n] = '\0';

    read_file_to_bst(trees, file_name);

    for (int i = 0; input[i]; i++)
    {

        input[i] = tolower(input[i]);
    }
    strcpy(input_choise, input);
    input_to_sent = strtok(input_choise, " ");
    input_to_sent = strtok(NULL, "");

    for (i = 0; i < ARR_LEN(menu); i++)
    {
        unsigned int len = strlen(menu[i]);
        if (!memcmp(input_choise, menu[i], len))
        {
            switch (i)
            {
            case 0:
                
                add_main(trees, input_to_sent, errors, file_name, new_sock);
                break;
            case 1:
                select_main(trees, input_to_sent, errors, new_sock);
                break;
            case 2:
                show_bst_in_order(trees[DEBT], new_sock);
                break;
          
            }
            
        }
        
    }
    
   

exit:
           if (i == ARR_LEN(menu))
        {
        sprintf(message, "%s it's not legal please try again\n", input_choise);
        strcpy(errors, message);
        puts("hdhhd");
        eroor_send(errors, new_sock);

        
        
        }
    close(new_sock);
    return NULL;
}

int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t len = sizeof(cliaddr);
    Args arg;
    arg.file_name = argv[2];

    if (argc < 2)
    {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("Error creating socket");
        return 1;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(atoi(argv[1]));
    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("Error binding socket");
        return 1;
    }

    if (listen(sockfd, 5) < 0)
    {
        perror("Error listenning");
        return 1;
    }

    while (1)
    {
        pthread_t tid;
        int new_sock = accept(sockfd, (struct sockaddr *)&cliaddr, (socklen_t *)&len);
        arg.new_sock = new_sock;
        if (new_sock < 0)
        {
            perror("accept failed");
            return 1;
        }

        pthread_create(&tid, NULL, conn_handler, (void *)&arg);
        pthread_join(tid, NULL);
    }

    return 0;
}
