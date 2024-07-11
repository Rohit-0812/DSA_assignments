#include "sort.h"

void swap(long long int *a, long long int *b){
    long long int temp = *a;
    *a = *b;
    *b = temp;
}

Heap Maxheap(int capacity) {
    Heap h = (Heap) calloc (1, sizeof(struct heap));
    h->data = (long long int*) calloc (capacity, sizeof(long long int));
    h->capacity = capacity;
    h->happiness = 0;
    h->size = 0;
    return h;
}

Heap heapify(Heap h, int index) {
    if (h->size <= 1)
        return h;
    
    int left = 2*index + 1; 
    int right = 2*index + 2; 
    int large = index; 
    if (left < h->size && h->data[left] > h->data[index]){
        large = left; 
    }
    if (right < h->size && h->data[right] > h->data[large]){
        large = right;
    } 
    if (large != index) { 
        swap(&h->data[index],&h->data[large]);
        h = heapify(h, large); 
    }

    return h;
}

Heap insert(Heap h, long long int element) {

    h->size++;
    h->data[h->size - 1] = element;
    int curr = h->size - 1;
    
    while (curr > 0 && h->data[(curr-1)/2] < h->data[curr]) {
        
        long long int temp = h->data[(curr-1)/2];
        h->data[(curr-1)/2] = h->data[curr];
        h->data[curr] = temp;
        
        curr = (curr-1)/2;
        h = heapify(h,h->size);
    }
    return h; 
}

Heap decrement(Heap h){
    if(h->data[0] <= 0){
        return h;
    }
    h->happiness = h->happiness + h->data[0];
    h->data[0]--;
    
    h = heapify(h,0);
    return h;
}