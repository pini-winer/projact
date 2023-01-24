#ifndef TREES_H
#define TREES_H

void insert_debt_bst(BST **root, Customers *customer);

void insert_id_bst(BST **root, Customers *customer);

void insert_date_bst(BST **root, Customers *customer);

void insert_phone_bst(BST **root, Customers *customer);

void insert_first_name_bst(BST **root, Customers *customer);

void insert_second_name_bst(BST **root, Customers *customer);

int convert_date_to_int(char *date);


#endif
