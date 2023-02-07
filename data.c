#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "data.h"
#include "trees.h"

int compare_id(BST *root, Customers *customer)
{
    if (root == NULL)
    {
        return 0;
    }

    if (customer->id == root->customer_pointer->id)
    {

        root->customer_pointer->debt += customer->debt;
        strcpy(root->customer_pointer->date, customer->date);
        free(customer);

        return 1;
    }

    if (customer->id < root->customer_pointer->id)
    {
        compare_id(root->left, customer);
    }
    else
    {
        compare_id(root->right, customer);
    }
    return 0;
}



void show_bst(BST *root, int new_sock)
{
    if (root == NULL)
    {
        return;
    }

    show_bst(root->left,new_sock);

    print_customer(root->customer_pointer,new_sock);
    show_bst(root->right,new_sock);
}

void show_bst_in_order(BST *root, int new_sock)
{
    if (root == NULL)
    {
        return;
    }

    show_bst_in_order(root->left,new_sock);
    print_customer(root->customer_pointer,new_sock);
    show_bst_in_order(root->right,new_sock);
}

Customers *seve_data(char *line)
{
    Customers *new;
    new = malloc(sizeof(Customers));

    if (!new)
    {
        return NULL;
    }

    char *data;

    data = strtok(line, ",");

    strcpy(new->first_name, data);
    data = strtok(NULL, ",");
    strcpy(new->second_name, data);
    data = strtok(NULL, ",");
    new->id = atof(data);
    data = strtok(NULL, ",");
    strcpy(new->date, data);
    data = strtok(NULL, ",");
    new->phone = atoi(data);
    data = strtok(NULL, ",");
    new->debt = atof(data);

    return new;
}

int read_file_to_bst(BST *trees[], char *str , int new_sock)
{
    FILE *file = fopen(str, "r");
    char line[1000];
    Customers *customer = NULL;

    while (fgets(line, 1000, file))
    {
        customer = seve_data(line);
        int i = compare_id(trees[ID], customer);
        if (!i)
        {
            insert_id_bst(&trees[ID], customer);
             insert_debt_bst(&trees[DEBT], customer);
             insert_date_bst(&trees[DATE], customer);
             insert_phone_bst(&trees[PHONE], customer);
             insert_first_name_bst(&trees[FIRST_NAME], customer);
              insert_second_name_bst(&trees[SECOND_NAME], customer);
        }
    }
    show_bst(trees[DEBT],new_sock);

    fclose(file);
    return 0;
}

