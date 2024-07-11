#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node *Queue;
struct Node{
    int data;
    struct Node *next;
};
Queue end = NULL;


void push(Queue Head, int val);
void Inject(Queue front, int val);
int Pop(Queue Head);
int popRear(Queue front);
void Print(Queue front);
void PrintReverse(Queue front);
int findElem(Queue front,int pos);
void removeKElems(Queue front,int k);

#endif