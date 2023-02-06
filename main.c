#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "main.h"
#include "data.h"
#include "select.h"
#include "add.h"


#define ARR_LEN(_arr) (sizeof(_arr)/sizeof(_arr[0]))

void print_customer(Customers *customer)
{
    printf("First name: %s\n", customer->first_name);
    printf("second name: %s\n", customer->second_name);
    printf("date: %s\n", customer->date);
    printf("ID: %d\n", customer->id);
    printf("Phone: 0%d\n", customer->phone);
    printf("Debt: %.2f\n", customer->debt);
    puts("\n");
}

void help(const char *menu[], int len)
{
    printf("Options: ");
    for (int i = 0; i < len; i++)
    {
        printf("%s ", menu[i]);
    }
    puts("");
}

void free_pointer_Recursion(BST *root)
{
    if (root == NULL)
    {
        return;
    }

    free_pointer_Recursion(root->left);
    free_pointer_Recursion(root->right);
    free(root->customer_pointer);
}
void free_tree_Recursion(BST *root)
{
    if (root == NULL)
    {
        return;
    }

    free_tree_Recursion(root->left);
    free_tree_Recursion(root->right);
    free(root);
}

void free_tree(BST *trees[], int num) {
    free_pointer_Recursion(trees[ID]);
    for (int i = 0; i < num; i++) {
        free_tree_Recursion(trees[i]);
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        return 1;
    }

    char* str = argv[1];
    
    
     const char *menu[] = {"set", "select", "print", "quit"};
    char input[MAX_LEN];
    char errors[MAX_LEN]={0};
    char input_choise[MAX_LEN];
    char *input_to_sent;       
    int i;
    BST *id_tree=NULL;
    BST *debt_tree=NULL;
    BST *date_tree=NULL;
    BST *phone_tree=NULL;
    BST *first_name_tree=NULL;
    BST *second_name_tree=NULL;
    
    
    
    BST *trees[] = {id_tree, debt_tree,  date_tree, phone_tree, first_name_tree, second_name_tree};

    
    read_file_to_bst(trees, str);
    
    
    while (1)
    {
        help(menu, ARR_LEN(menu));
        fgets(input, sizeof(input), stdin);
        
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
                switch(i)
                {
                    case 0: 
                    // add
                   add_main(trees, input, errors, str);           
                   break;
                    case 1:
                    // select
                        select_main(trees, input_to_sent, errors);
                        break;
                    case 2:
                    // print
                        show_bst_in_order(trees[DEBT]);
                        break;
                    case 3:
                        // quit 
                        goto exit;
                        break;
                    
                    default:
                        break;
                }
                break;
            }
        }
         
           printf("%s", errors); 

                
        if (i == ARR_LEN(menu))
        {
            printf("Error! No such option. ");
        }
    }

exit:
    
    free_tree(trees, ARR_LEN(trees));
    return 0;
}
