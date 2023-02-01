#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "main.h"
#include "data.h"
#include "trees.h"
#include "select.h"

BST *max(BST *root)
{
    if (root == NULL || root->right == NULL)
    {
        return root;
    }
    return max(root->right);
}

void delete_date(BST **root, Customers *customer)
{
    if (*root == NULL)
    {
        return;
    }

    if ((*root)->customer_pointer->id == customer->id)
    {

        (*root)->customer_pointer->debt += customer->debt;
        strcpy((*root)->customer_pointer->date, customer->date);

        if ((*root)->left == NULL && (*root)->right == NULL)
        {
            free(*root);
            *root = NULL;
        }
        else if ((*root)->left != NULL && (*root)->right != NULL)
        {
            BST *tmp = max((*root)->left);
            (*root)->customer_pointer = tmp->customer_pointer;
            delete_date(&((*root)->left), customer);
        }
        else
        {
            BST *tmp = (*root)->left ? (*root)->left : (*root)->right;
            free(*root);
            *root = tmp;
        }
    }
    else
    {
        if ((*root)->customer_pointer->id > customer->id)
        {
            delete_date(&((*root)->left), customer);
        }
        else
        {
            delete_date(&((*root)->right), customer);
        }
    }
}

void delete_dabt(BST **root, Customers *customer)
{
    if (*root == NULL)
    {
        return;
    }

    if ((*root)->customer_pointer->id == customer->id)
    {

        if ((*root)->left == NULL && (*root)->right == NULL)
        {
            free(*root);
            *root = NULL;
        }
        else if ((*root)->left != NULL && (*root)->right != NULL)
        {
            BST *tmp = max((*root)->left);
            (*root)->customer_pointer = tmp->customer_pointer;
            delete_dabt(&((*root)->left), customer);
        }
        else
        {
            BST *tmp = (*root)->left ? (*root)->left : (*root)->right;
            free(*root);
            *root = tmp;
        }
    }
    else
    {
        if ((*root)->customer_pointer->debt > customer->debt)
        {
            delete_dabt(&((*root)->left), customer);
        }
        else
        {
            delete_dabt(&((*root)->right), customer);
        }
    }
}

int find_if_id_good(BST *root, Customers *customer, char *errors)
{
    char first_name_temp[60] = {0};
    char first_name_customer[60] = {0};
    char second_name_temp[60] = {0};
    char second_name_customer[60] = {0};
    if (root == NULL)
    {
        return 0;
    }
    remove_spaces(root->customer_pointer->first_name, first_name_temp);
    remove_spaces(customer->first_name, first_name_customer);
    remove_spaces(root->customer_pointer->second_name, second_name_temp);
    remove_spaces(customer->second_name, second_name_customer);

    if (root->customer_pointer->id == customer->id)
    {
        if (strcmp(second_name_temp, second_name_customer) != 0 || strcmp(first_name_temp, first_name_customer) != 0)
        {
            char message[] = "id is in use\n";
            strcpy(errors, message);
            return 1;
        }
    }
    return 2;
    return find_if_id_good(root->left, customer, errors) || find_if_id_good(root->right, customer, errors);
}

int parseLine(char *input, char *first_name, char *second_name, char *id, char *phone, char *date, char *dept, char *errors)
{
    char *token = strtok(input, ",");
        int counter = 0;

    while (token != NULL)
    {
        if (counter == 0 && sscanf(token, " first name = %60s", first_name) == 1)
        {
            counter++;
        }
        else if (counter == 1 && sscanf(token, " second name = %60s", second_name) == 1)
        {
            counter++;
        }
        else if (counter == 2 && sscanf(token, " id = %19s", id) == 1)
        {
            counter++;
        }
        else if (counter == 3 && sscanf(token, " phone = %19s", phone) == 1)
        {
            counter++;
        }
        else if (counter == 4 && sscanf(token, " date = %19s", date) == 1)
        {
            counter++;
        }
        else if (counter == 5 && sscanf(token, " dept = %19s", dept) == 1)
        {
            counter++;
        }
        else
        {
            char message[90] = {0};
            sprintf(message, "Error: Invalid format in: %s\n", token);
            strcpy(errors, message);

            return 1;
        }
        token = strtok(NULL, ",");
    }
    printf("first_name=%s\n", first_name);
    printf("second_name=%s\n", second_name);
    printf("id=%s\n", id);
    printf("phone=%s\n", phone);
    printf("date=%s\n", date);
    printf("dept=%s\n", dept);
    return 0;
}

int chack_data(char *first_name, char *second_name, char *id, char *phone, char *date, char *dept, char *errors)
{
    if (strlen(id) > 9 || !isdigit(id[0]))
    {
        char message[] = "ID should contain no more than 9 digits\n";
        strcpy(errors, message);
        return 1;
    }
    else
    {
        for (int i = 0; i < strlen(id); i++)
        {
            if (!isdigit(id[i]))
            {
                char message[] = "ID should contain no more than 9 digits\n";
                strcpy(errors, message);
                return 1;
            }
        }
    }

    int len = strlen(first_name);
    for (int i = 0; i < len; i++)
    {
        if (!isalpha(first_name[i]))
        {
            char message[90] = {0};
            sprintf(message, "Error: Invalid format in: %s\n", first_name);
            strcpy(errors, message);
            return 1;
        }
    }
    len = strlen(second_name);
    for (int i = 0; i < len; i++)
    {
        if (!isalpha(second_name[i]))
        {
            char message[90] = {0};
            sprintf(message, "%s must to be a  letter\n" ,second_name);
            strcpy(errors, message);
            return 1;
        }
    }

    return 0;
}

Customers *seve_add_data(char *first_name, char *second_name, char *id, char *phone, char *date, char *dept)
{
    Customers *new;
    new = malloc(sizeof(Customers));

    if (!new)
    {
        return NULL;
    }

    strcpy(new->first_name, first_name);
    strcpy(new->second_name, second_name);
    new->id = atof(id);
    strcpy(new->date, date);
    new->phone = atoi(phone);

    new->debt = atof(dept);

    if (new->debt < 0)
    {
        new->debt = abs(new->debt);
    }
    else
    {
        new->debt = abs(new->debt) * -1;
    }

    return new;
}

void add_main(BST *trees[], char *input, char *errors, char *str)
{
    int i;
    int x;
    FILE *file = fopen(str, "a");
    Customers *customer = NULL;
    Customers *temp_customer_pointer = NULL;
    char first_name[30] = {0};
    char second_name[30] = {0};
    char id[20] = {0};
    char phone[20] = {0};
    char date[20] = {0};
    char dept[20] = {0};
    char line[] = "first name=Moshe, second nage=efddesky, id=123456789, phone=0544123456,date=3/4/2022, dept=-400";

    i = parseLine(line, first_name, second_name, id, phone, date, dept, errors);
    if (i)
    {
        return;
    }
    chack_data(first_name, second_name, id, phone, date, dept, errors);
    customer = seve_add_data(first_name, second_name, id, phone, date, dept);
    x = find_if_id_good(trees[ID], customer, errors);
    if (x == 2)
    {
        fprintf(file, "%s,%s,%d,%s,%d,%f\n", customer->first_name, customer->second_name, customer->id, customer->date, customer->phone, customer->debt);

        delete_date(&trees[DEBT], customer);
        delete_dabt(&trees[DATE], customer);
        insert_debt_bst(&trees[DEBT], customer);
        insert_date_bst(&trees[DATE], customer);
        free(customer);
    }
    if (x == 0)
    {
        insert_id_bst(&trees[ID], customer);
        insert_debt_bst(&trees[DEBT], customer);
        insert_date_bst(&trees[DATE], customer);
        insert_phone_bst(&trees[PHONE], customer);
        insert_first_name_bst(&trees[FIRST_NAME], customer);
        insert_second_name_bst(&trees[SECOND_NAME], customer);
        fprintf(file, "%s,%s,%d,%s,%d,%f\n", customer->first_name, customer->second_name, customer->id, customer->date, customer->phone, customer->debt);
    }

    fclose(file);
}