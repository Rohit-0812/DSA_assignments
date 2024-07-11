#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

void sort(int n,int **a1)
{
    int i=0, temp1, temp2, temp3;
    while( i < n - 1){
        int j=0;
        while( j < n - i - 1){
               
            if (a1[1][j] > a1[1][j + 1]){
                temp1 = a1[1][j];
                a1[1][j] = a1[1][j + 1];
                a1[1][j + 1] = temp1;
                    
                temp2 = a1[0][j];
                a1[0][j] = a1[0][j + 1];
                a1[0][j + 1] = temp2;
                    
                temp3 = a1[2][j];
                a1[2][j] = a1[2][j + 1];
                a1[2][j + 1] = temp3;
            }
            j++;
        }
        i++;
    }
     
}


