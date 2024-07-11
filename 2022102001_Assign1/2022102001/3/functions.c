#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "functions.h"

struct Node *createalist();
void Print(struct Node *);
struct Node * Find(struct Node *,int);
void Insert(struct Node *,int );
struct Node
{
    int element;
    struct Node *  next;
};

void Print(struct Node * head)
{
    struct Node * ptr = head-> next;
    while(ptr != head)
    {
        printf("%d ",ptr->element);
        ptr = ptr-> next;
    }
    printf("\n");
}
void Insert(struct Node * head,int num)
{
    
    struct Node * NNode = (struct Node *)malloc(sizeof(struct Node));
    NNode->element = num;
        NNode-> next = head-> next;

    head-> next = NNode;
    // struct Node * NNode = (struct Node *)malloc(sizeof(struct Node));
    // NNode->element = num;
    // if(!head)
    // {
    //     NNode-> next = NNode;
    //     return ;
    // }
    // else
    // {
    //     struct Node * ptr = head;
    //     while(ptr-> next != head)
    //         ptr = ptr-> next;
    //     ptr-> next = NNode;
    //     NNode-> next = head;
    // }
}
struct Node * Find(struct Node * head,int num)
{
    struct Node * ptr = head-> next;
    while(ptr != head)
    {
        if(ptr->element == num)
        {
            return ptr;
        }
        ptr = ptr-> next;
    }
    return (ptr->element == num)?ptr:NULL;
}