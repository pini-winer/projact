#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "main.h"
#include "data.h"
#include "trees.h"
#define MAX_LEN 100
#define true 1
#define false 0
#define ARR_LEN(_arr) (sizeof(_arr) / sizeof(_arr[0]))

void remove_spaces(char *input, char *new_input)
{
    int i, j;
    int x = 0;
    int len = strlen(input);
    for (i = 0; input[i] == ' '; i++)
        ;
    for (j = len - 1; input[j] == ' '; j--)
        ;

    for (; i <= j; i++, x++)
    {
        new_input[x] = input[i];
    }
    new_input[x] = '\0';
}



void find_first_name(BST *root, char *name, int operator_to_check)
{
    char *name_temp;
    char first_name_temp[MAX_LEN] = {0};

    if (root == NULL)
    {
        return;
    }

    name_temp = strchr(name, '\n');
    if (name_temp)
    {
        *name_temp = '\0';
    }

    remove_spaces(root->customer_pointer->first_name, first_name_temp);
    
    
    if (operator_to_check == 0){
    if (strcmp(first_name_temp, name) == 0)
    {
        print_customer(root->customer_pointer);
    }
    }
    if (operator_to_check == 1){
    if (strcmp(first_name_temp, name) != 0)
    {
        print_customer(root->customer_pointer);
    }
    }
    if (operator_to_check == 2){
    if (strcmp(first_name_temp, name) < 0)
    {
        print_customer(root->customer_pointer);
    }
    }
    if (operator_to_check == 3){
    if (strcmp(first_name_temp, name) > 0)
    {
        print_customer(root->customer_pointer);
    }
    }
    
    find_first_name(root->left, name, operator_to_check);
    find_first_name(root->right, name, operator_to_check);
}
    

void find_second_name(BST *root, char *name, int operator_to_check)
{
    char *name_temp;
    char second_name_temp[MAX_LEN] = {0};

    if (root == NULL)
    {
        return;
    }

    name_temp = strchr(name, '\n');
    if (name_temp)
    {
        *name_temp = '\0';
    }

    remove_spaces(root->customer_pointer->second_name, second_name_temp);
        
    if (operator_to_check == 0 && strcmp(second_name_temp, name) == 0)
    {
        print_customer(root->customer_pointer);
    }
    
    
    if (operator_to_check == 1 && strcmp(second_name_temp, name) != 0)
    {
        print_customer(root->customer_pointer);
    }
    
    if (operator_to_check == 2 && strcmp(second_name_temp, name) < 0)
    {
        print_customer(root->customer_pointer);
    }
    
    
    if (operator_to_check == 3 && strcmp(second_name_temp, name) > 0)
    {
        print_customer(root->customer_pointer);
    }
    
    
    find_second_name(root->left, name, operator_to_check);
    find_second_name(root->right, name, operator_to_check);
}
    
void find_debt(BST *root, int debt, int operator_to_check)
{
    if (root == NULL)
    {
        return;
    }

   
   
    if (operator_to_check == 0 && root->customer_pointer->debt == debt)
    {
        print_customer(root->customer_pointer);
    }
    if (operator_to_check == 1 && root->customer_pointer->debt != debt)
    {
        print_customer(root->customer_pointer);
    }
    if (operator_to_check == 2 && root->customer_pointer->debt < debt)
    {
        print_customer(root->customer_pointer);
    }
    if (operator_to_check == 3 && root->customer_pointer->debt > debt)
    {
        print_customer(root->customer_pointer);
    }
    
    find_debt(root->left, debt, operator_to_check);
    find_debt(root->right, debt, operator_to_check);
}
void find_id(BST *root, int id, int operator_to_check)
{
    if (root == NULL)
    {
        return;
    }

   
   
    if (operator_to_check == 0 && root->customer_pointer->id == id)
    {
        print_customer(root->customer_pointer);
    }
    if (operator_to_check == 1 && root->customer_pointer->id != id)
    {
        print_customer(root->customer_pointer);
    }
    if (operator_to_check == 2 && root->customer_pointer->id < id)
    {
        print_customer(root->customer_pointer);
    }
    if (operator_to_check == 3 && root->customer_pointer->id > id)
    {
        print_customer(root->customer_pointer);
    }
    
    find_id(root->left, id, operator_to_check);
    find_id(root->right, id, operator_to_check);
}
void find_phone(BST *root, int phone, int operator_to_check)
{
    if (root == NULL)
    {
        return;
    }

   
   
    if (operator_to_check == 0 && root->customer_pointer->phone == phone)
    {
        print_customer(root->customer_pointer);
    }
    if (operator_to_check == 1 && root->customer_pointer->id != phone)
    {
        print_customer(root->customer_pointer);
    }
    if (operator_to_check == 2 && root->customer_pointer->id < phone)
    {
        print_customer(root->customer_pointer);
    }
    if (operator_to_check == 3 && root->customer_pointer->id > phone)
    {
        print_customer(root->customer_pointer);
    }
    
    find_phone(root->left, phone, operator_to_check);
    find_phone(root->right, phone, operator_to_check);
}

void find_date(BST *root, int date, int operator_to_check)
{
    if (root == NULL)
    {
        return;
    }

   
   
    if (operator_to_check == 0 && convert_date_to_int(root->customer_pointer->date) == date)
    {
        print_customer(root->customer_pointer);
    }
    if (operator_to_check == 1 && convert_date_to_int(root->customer_pointer->date) != date)
    {
        print_customer(root->customer_pointer);
    }
    if (operator_to_check == 2 && convert_date_to_int(root->customer_pointer->date) < date)
    {
        print_customer(root->customer_pointer);
    }
    if (operator_to_check == 3 && convert_date_to_int(root->customer_pointer->date) > date)
    {
        print_customer(root->customer_pointer);
    }
    
    find_phone(root->left, date, operator_to_check);
    find_phone(root->right, date, operator_to_check);
}




char check_input(char *input, char *category, char *sarch)
{
    char operators[] = { '!', '=', '>', '<'};
    char first[MAX_LEN];
    char last[MAX_LEN];
    char *operator;
    char new_operator;

    
    for (int i = 0; i < sizeof(operators); i++)
    {
        operator= strchr(input, operators[i]);
        if (operator)
        {
            
            new_operator = *operator;
            break;
        }
    }
    if (!operator)
    {
        printf(" Invalid operator please try again\n");
        return new_operator;
    }

    strncpy(first, input, operator- input);
    first[operator - input] = '\0';
    if(new_operator == '!'){
        
    strcpy(last, operator+ 2);
    }
    else{
        
    strcpy(last, operator+ 1);
    }
    remove_spaces(first, category);
    remove_spaces(last, sarch);
    return new_operator;
}

int char_to_int(char str[])
{
    int result = 0;
    int len = strlen(str);
    int i;
    for (i = 0; i < len; i++)
    {
        if (isspace(str[i]))
        {
            continue;
        }
        else if (isdigit(str[i]))
        {
            result = result * 10 + (str[i] - '0');
        }
        else
        {
            return -1;
        }
    }
    return result;
}

int select_main(BST *trees[], char *input)
{

    char category[MAX_LEN] = {0};
    char sarch[MAX_LEN] = {0};
    char operator;

    operator= check_input(input, category, sarch);
    
    if (!category)
    {
        printf(" Invalid category please try again\n");

        return 2;
    }
    if (!operator)
    {
        return 4;
    }
    if (!sarch)
    {
        printf(" Invalid sarch filed please try again\n");

        return 3;
    }

    const char *category_menu[] = {"first name", "second name", "id", "debt", "phone", "date"};
    char operators[] = {'=', '!', '>', '<'};

    int num_form_char;
    int x = 0;
    for (int i = 0; i < ARR_LEN(category_menu); i++)
    {
        unsigned int len = strlen(category_menu[i]);
        if (!memcmp(category, category_menu[i], len))
        {
            switch (i)
            {
                
            case 0:
                // first name
                if (operator == operators[0])
                {

                    find_first_name(trees[FIRST_NAME], sarch, 0);
                }
                if (operator== operators[1])
                {
                   find_first_name(trees[FIRST_NAME], sarch, 1);
                }
                if (operator== operators[2])
                {
                    find_first_name(trees[FIRST_NAME], sarch, 2);
                }
                if (operator== operators[3])
                {
                    find_first_name(trees[FIRST_NAME], sarch, 3);
                }

                x = 1;

                break;
                
            case 1:
                // second name
               if (operator== operators[0])
                {

                    find_second_name(trees[SECOND_NAME], sarch, 0);
                }
                if (operator== operators[1])
                {
                   find_second_name(trees[SECOND_NAME], sarch, 1);
                }
                if (operator== operators[2])
                {
                    find_second_name(trees[SECOND_NAME], sarch, 2);
                }
                if (operator== operators[3])
                {
                    find_second_name(trees[SECOND_NAME], sarch, 3);
                }
                x = 1;
                break;
                
            case 2:
                // id
                num_form_char = char_to_int(sarch);
                if (num_form_char == -1)
                {
                    printf("%s its not a number please try again \n", sarch);
                    return 1;
                }
                if (operator== operators[0])
                {

                    find_id(trees[ID], num_form_char, 0);
                }
                if (operator== operators[1])
                {
                   find_id(trees[ID], num_form_char, 1);
                }
                if (operator== operators[2])
                {
                    find_id(trees[ID], num_form_char, 2);
                }
                if (operator== operators[3])
                {
                    find_id(trees[ID], num_form_char, 3);
                }

                x = 1;
                break;
                
            case 3:
                // debt
                num_form_char = char_to_int(sarch);
                if (num_form_char == -1)
                {
                    printf("%s its not a number please try again \n", sarch);
                    return 1;
                }
                
                
                if (operator== operators[0])
                {

                    find_debt(trees[ID], num_form_char, 0);
                }
                if (operator== operators[1])
                {
                   find_debt(trees[ID], num_form_char, 1);
                }
                if (operator== operators[2])
                {
                    find_debt(trees[ID], num_form_char, 2);
                }
                if (operator== operators[3])
                {
                    find_debt(trees[ID], num_form_char, 3);
                }

                x = 1;

                break;
                
            case 4:
                // phone
               num_form_char = char_to_int(sarch);
                if (num_form_char == -1)
                {
                    printf("%s its not a number please try again \n", sarch);
                    return 1;
                }
                
                
                if (operator== operators[0])
                {

                    find_phone(trees[ID], num_form_char, 0);
                }
                if (operator== operators[1])
                {
                   find_phone(trees[ID], num_form_char, 1);
                }
                if (operator== operators[2])
                {
                    find_phone(trees[ID], num_form_char, 2);
                }
                if (operator== operators[3])
                {
                    find_phone(trees[ID], num_form_char, 3);
                }
                x = 1;
                break;
                
            case 5:
                // date
               num_form_char = convert_date_to_int(sarch);
                if (num_form_char == -1)
                {
                    printf("%s its not a number please try again \n", sarch);
                    return 1;
                }
                
                
                if (operator== operators[0])
                {

                    find_date(trees[ID], num_form_char, 0);
                }
                if (operator== operators[1])
                {
                   find_date(trees[ID], num_form_char, 1);
                }
                if (operator== operators[2])
                {
                    find_date(trees[ID], num_form_char, 2);
                }
                if (operator== operators[3])
                {
                    find_date(trees[ID], num_form_char, 3);
                }

                x = 1;

                break;

            default:
                break;
            }
            break;
        }
    }
    if (!x)
        printf("%s it's not legal please try again\n", category);
    return 0;
}
