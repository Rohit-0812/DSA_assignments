#ifndef HEAP_H
#define HEAP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct heap *Heap;
struct heap {
    int* data;
    int size;
    int capacity;
    int sum;
};

void swap(int *a, int *b);
Heap Minheap(int capacity);
Heap heapify(Heap h, int index);
Heap insert(Heap h, int element);
Heap rem_top(Heap h);

#endif