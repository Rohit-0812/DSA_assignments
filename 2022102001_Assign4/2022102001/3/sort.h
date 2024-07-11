#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);
int compare(int a, int b);
int strings(char *A, char *B, int len1, int len2);
void heapify(char **input, int n, int index, int *len);
void Sort(char** arr, int n, int* len);

#endif