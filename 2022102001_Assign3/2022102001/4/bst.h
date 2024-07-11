#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node *tree;
struct node{
    int data;
    tree left;
    tree right;
};


tree NNode(int val);
tree insert(tree t, int val);
int a=-1;
void inor(tree t, int *arr);
tree ListToBST(int *arr, int len);
void swap(int *arr,int j, int n);

#endif