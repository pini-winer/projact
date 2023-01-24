#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int convert_date_to_int(char *date)
{
    int day, month, year;
    sscanf(date, "%d/%d/%d", &day, &month, &year);
    year = year % 100;
    return year * 10000 + month * 100 + day;
}

void insert_date_bst(BST **root, Customers *customer)
{
    int i = convert_date_to_int(customer->date);

    if (*root == NULL)
    {
        *root = calloc(1, sizeof(BST));

        (*root)->customer_pointer = customer;
        return;
    }
    if (i <= convert_date_to_int((*root)->customer_pointer->date))
    {
        insert_date_bst(&(*root)->left, customer);
    }
    else
    {
        insert_date_bst(&(*root)->right, customer);
    }
}

void insert_debt_bst(BST **root, Customers *customer)
{
    if (*root == NULL)
    {
        *root = calloc(1, sizeof(BST));
        (*root)->customer_pointer = customer;
        return;
    }
    if (customer->debt <= (*root)->customer_pointer->debt)
    {
        insert_debt_bst(&(*root)->left, customer);
    }
    else
    {
        insert_debt_bst(&(*root)->right, customer);
    }
}

void insert_id_bst(BST **root, Customers *customer)
{
    if (*root == NULL)
    {
        *root = calloc(1, sizeof(BST));
        (*root)->customer_pointer = customer;
        return;
    }
    if (customer->id <= (*root)->customer_pointer->id)
    {
        insert_id_bst(&(*root)->left, customer);
    }
    else
    {
        insert_id_bst(&(*root)->right, customer);
    }
}

void insert_phone_bst(BST **root, Customers *customer)
{
    if (*root == NULL)
    {
        *root = calloc(1, sizeof(BST));
        (*root)->customer_pointer = customer;
        return;
    }
    if (customer->phone <= (*root)->customer_pointer->phone)
    {
        insert_phone_bst(&(*root)->left, customer);
    }
    else
    {
        insert_phone_bst(&(*root)->right, customer);
    }
}

void insert_first_name_bst(BST **root, Customers *customer)
{
    if (*root == NULL)
    {
        *root = calloc(1, sizeof(BST));
        (*root)->customer_pointer = customer;
        return;
    }
    if (strcmp((*root)->customer_pointer->first_name, customer->first_name) > 0)
    {
        insert_first_name_bst(&(*root)->left, customer);
    }
    else
    {
        insert_first_name_bst(&(*root)->right, customer);
    }
}

void insert_second_name_bst(BST **root, Customers *customer)
{
    if (*root == NULL)
    {
        *root = calloc(1, sizeof(BST));
        (*root)->customer_pointer = customer;
        return;
    }

    if (strcmp((*root)->customer_pointer->second_name, customer->second_name) > 0)
    {
        insert_second_name_bst(&(*root)->left, customer);
    }
    else
    {
        insert_second_name_bst(&(*root)->right, customer);
    }
}
