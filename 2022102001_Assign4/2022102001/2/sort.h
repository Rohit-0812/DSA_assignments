#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

void swap(long long int* a, long long int* b);
void heapify(long long int arr[], long long int n, long long int i,long long int ind[], long long int b[]);
void compare(long long int j2[], long long int a[], long long int b[], long long int m);
void insert(long long int arr[], long long int n, long long int ind[], long long int b[]);

#endif