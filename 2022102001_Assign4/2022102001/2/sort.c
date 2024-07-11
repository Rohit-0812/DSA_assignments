#include "sort.h"

void swap(long long int* a, long long int* b) {
    long long int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(long long int arr[], long long int n, long long int i,long long int ind[], long long int b[]) {
    long long int index = i;    
    long long int left = 2*i+1;    
    long long int right = 2*i+2;   
    if (left < n && arr[left] > arr[index]){
        index = left;
    }
    else if(left < n && arr[left] == arr[index] && b[left] > b[index]){        
                  
        index = left;
        
    }    
    if (right < n && arr[right] > arr[index]){
        index = right;
    }    
    
    else if(right < n && arr[right] == arr[index] && b[right] > b[index]){
        
        index = right;
        
    }

    if (index != i){
        swap(&arr[i], &arr[index]);
        swap(&ind[i], &ind[index]);
        swap(&b[i], &b[index]);
        
        heapify(arr, n, index,ind, b);
    }
}

void compare(long long int j2[], long long int a[], long long int b[], long long int m){
    if(a[0] > b[0]){
        j2[0] = b[0];
    }
    else{
        j2[0] = a[0];
    }
    for(int j=1;j<m;j++){
        if(b[j] <= a[j] && j2[j-1] <= b[j]){
            j2[j] = b[j];
        }
        else if(b[j] >= a[j] && j2[j-1] <= a[j]){
            j2[j] = a[j];
        }
        else if(b[j] <= a[j] && j2[j-1] >= b[j]){
            j2[j] = a[j];
        }
        else if(b[j] >= a[j] && j2[j-1] >= a[j]){
            j2[j] = b[j];
        }
        else{
            j2[j] = a[j];
        }
    }
}

void insert(long long int arr[], long long int n, long long int ind[], long long int b[]) {
    
    for (long long int i = (n/2)-1 ; i >= 0; i--)
        heapify(arr, n, i,ind,b);
    for (long long int i = n-1;i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        swap(&ind[0],&ind[i]);
        swap(&b[0], &b[i]); 

        heapify(arr, i, 0,ind, b);
    }    
}
