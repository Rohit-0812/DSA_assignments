#ifndef HASH_H
#define HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 11

int TABLESIZE = 10000007;

typedef struct hash * Hash;
typedef struct node * Node;

struct hash{
    int TABLESIZE;
    Node *pStart;
};

struct node{
    char data[MAX];
    int freq1[26];
    Node pNext;
    Node pPrev;
};

int ascii(char inp);
int power(int a, int b);
int hashing(char *input);
void insert(Hash myHT, char *input, int *freq1);
int check(int *freq1, int *freq);
void search(char *qry, Hash myHT,int *freq);


#endif