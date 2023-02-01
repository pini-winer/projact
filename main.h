#ifndef MAIN_H
#define MAIN_H

#define CHAR_ARRAY_LEN 30
#define MAX_LEN 250

typedef struct _Customers
{
    char first_name[CHAR_ARRAY_LEN];
    char second_name[CHAR_ARRAY_LEN];
    int id;
    char date[11];
    int phone;
    float debt;
} Customers;


typedef struct _BST
{
    Customers *customer_pointer;
    struct _BST *left, *right;
} BST;

typedef enum {
    ID,
    DEBT,
    DATE,
    PHONE,
    FIRST_NAME,
    SECOND_NAME
} SortField;



typedef enum {
    EQUAL,
    NOT_EQUAL,
    BIGGER,
    SMALLER
} OperatorField;


void print_customer(Customers *customer);


#endif
