#include<stdio.h>
#include<stdlib.h>
#include "functions.h"

void reverseString(char* str, int length){
    // int j=length-1;
    // // 
    // for(int i=0;i<length/2;i++){
    //     char temp = str[i];
    //     str [i] = str[j];
    //     str[j] = temp;
    //     j--;
    // }
    // // 
    // for(int k=0;k<length;k++){
    //     printf("%c",str[k]);
    // }
    // printf("\n");
    
    for(int i=length-1;i>=0;i--){
        printf("%c",str[i]);
    }
   
    printf("\n");
           
}

char* compressString(char* str, int len) {
    
    char* compress = (char*)malloc(sizeof(char)*(len * 2 +1));
    // if (!compress) {
    //     printf("Error\n");
    //     return NULL;
    // }

    
    int count = 1, j = 0, i = 0;
    
    while (i < len) {
        if ((i+1) < len && str[i] == str[i+1]) {
            count++;
        } 
        
        else {
            compress[j++] = str[i];
        //    sprintf(*(compress+(j+1)),"%d",count);
            if(count>9 && count<100){
                int temp = count%10;
                count = count/10;
                compress[j++] = count + '0';
                compress[j++] = temp + '0';
            }
            else if(count>99 && count<1000){
                int f = count%10;
                count = count/10;
                int q = count%10;
                count = count/10;
                compress[j++] = count + '0';
                compress[j++] = q + '0';
                compress[j++] = f + '0';

            }
             else if(count>999 && count<10000){
                   int f = count%10;
                   count = count/10;
                   int q = count%10;
                   count = count/10;
                   int r = count%10;
                   count = count/10;
                   compress[j++] = count + '0';
                   compress[j++] = r + '0';
                   compress[j++] = q + '0';
                   compress[j++] = f + '0';

               }
             else if(count == 10000){
                   compress[j++] = '1';
                   compress[j++] = '0';
                   compress[j++] = '0';
                   compress[j++] = '0';
                   compress[j++] = '0';
               }
        
            else if(count<=9){
                compress[j++] = count + '0';
            }
            count = 1;
            
        }
        i++;
        
        
    }
        compress[j] = '\0';
    
    

    return compress;
}

int* uniqueElements(int* arr, int length) {
    int* unique_arr = malloc(sizeof(int)*length); 
    int unique_count ; 
    
    unique_count=0;
    for(int i = 0;i < length;i++) {
        int j;
        
        for (j = 0; j < unique_count; j++) {
            if (arr[i] == unique_arr[j]) {
                break; 
            }
        }
        if (j == unique_count) {
            unique_arr[unique_count] = arr[i];
            
            unique_count++;
            
        }
        
    }
    
    for(int k=0;k<unique_count;k++){
        printf("%d ",unique_arr[k]);
    }
    
    // free(unique_arr);

}

int** transpose(int** matrix, int NumRow, int NumCol) {
    int** transposed = (int**) malloc(NumCol * sizeof(int*)); // allocate memory for transposed matrix
    for (int i = 0; i < NumCol; i++) {
        transposed[i] = (int*) malloc(NumRow * sizeof(int));
    }
    for (int i = 0; i < NumRow; i++) {
        for (int j = 0; j < NumCol; j++) {
            
            transposed[j][i] = matrix[i][j]; 
        }
    }
    return transposed;
    //free(transposed);
}

