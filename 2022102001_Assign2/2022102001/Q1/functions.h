#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>

struct Node{
    char data;
    struct Node* next;
};


char presence(char c[]);
void push(struct Node** top,char ch);
char pop(struct Node** top);
int check(char c1,char c2);
int balance(char c[]);
int strlength(char c[]);

#endif