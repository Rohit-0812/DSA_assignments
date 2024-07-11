#include "heap.h"

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

Heap Minheap(int capacity) {
    Heap h = (Heap) calloc (1, sizeof(struct heap));
    h->data = (int*) calloc (capacity, sizeof(int));
    h->capacity = capacity;
    h->sum = 0;
    h->size = 0;
    return h;
}

Heap heapify(Heap h, int index) {
    if (h->size <= 1)
        return h;
    
    int left = 2*index + 1; 
    int right = 2*index + 2; 

    
    int least = index; 
    
    
    if (left < h->size && h->data[left] < h->data[index]) 
        least = left; 
    
    
    if (right < h->size && h->data[right] < h->data[least]) 
        least = right; 

    if (least != index) 
    { 
        swap(&h->data[index],&h->data[least]);
        h = heapify(h, least); 
    }

    return h;
}

Heap insert(Heap h, int element) {

    h->size++;
    h->data[h->size - 1] = element;
    h->sum = h->sum + element;
    
    int curr = h->size - 1;
    
    while (curr > 0 && h->data[(curr-1)/2] > h->data[curr]) {
        
        int temp = h->data[(curr-1)/2];
        h->data[(curr-1)/2] = h->data[curr];
        h->data[curr] = temp;
        
        curr = (curr-1)/2;
        h = heapify(h,h->size);
    }
    return h; 
}



Heap rem_top(Heap h) {
   
    if (!h || h->size == 0)
        return h;

    int size = h->size;
    int last_element = h->data[size-1];
    h->sum = h->sum - h->data[0];
   
    h->data[0] = last_element;

   
    h->size--;
    size--;

    
    h = heapify(h, 0);
    return h;
}