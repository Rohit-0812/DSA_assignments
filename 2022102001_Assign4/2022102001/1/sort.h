#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

typedef struct heap *Heap;
struct heap {
    long long int* data;
    int size;
    int capacity;
    long long int happiness;
};

void swap(long long int *a, long long int *b);
Heap Maxheap(int capacity);
Heap heapify(Heap h, int index);
Heap insert(Heap h, long long int element);
Heap decrement(Heap h);

#endif