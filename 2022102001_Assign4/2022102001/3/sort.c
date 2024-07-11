#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int compare(int a, int b){
    if(a<b){
        return a;
    }
    else{
        return b;
    }
}

int strings(char *A, char *B, int len1, int len2){
    int i=0;
    int min = compare(len1,len2);
    int minstr;
    if(min == len1){
        minstr = 1;
    }
    else{
        minstr = 2;
    }
    for(i=0;i<min;i++){
        if(A[i] != B[i]){
            if(((i+1)%2 == 0 && A[i] > B[i]) || ((i+1)%2 != 0 && A[i] < B[i])){
                return 1;
            }
            else{
                return 0;
            }
        }
    }
    if((i == min && minstr == 1) && len1%2 != 0){
        return 1;
    }
    if((i == min && minstr == 2) && len2%2 == 0){
        return 1;
    }
    return 0;
}

void heapify(char **input, int n, int index, int *len){
    int large = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int left_val = (left < n && strings(input[left], input[large], len[left], len[large]));
    if((left_val) == 1 && left < n){
        large = left;
    }
    int right_val = (right <n &&  strings(input[right], input[large], len[right], len[large]));
    if((right_val) == 1 && right < n){
        large = right;
    }
    if(large != index){
        char *temp = input[index];
        input[index] = input[large];
        input[large] = temp;
        
        swap(&len[index],&len[large]);

        heapify(input,n,large,len);
    }
}

void Sort(char** arr, int n, int* len){
    for (int i =(n/2)-1;i>=0;i--)
    {
        heapify(arr,n,i,len);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        char *temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        swap(&len[0],&len[i]);

        heapify(arr, i, 0,len);
    }
}

