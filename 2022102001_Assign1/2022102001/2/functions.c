#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "functions.h"


 int* intersectionArray(int* arr1, int* arr2, int lenArr1, int lenArr2){
    
    int minlen,k = 0;
    
    if(lenArr1<=lenArr2){
        minlen = lenArr1;
    }
    else{
        minlen = lenArr1;
    }
    int* intArr = (int*)malloc(sizeof(int)*minlen);
    for(int i=0;i<lenArr1;i++){
        for(int j=0;j<lenArr2;j++){
            if(arr1[i]==arr2[j]){
                intArr[k] = arr1[i];
                k++;
            }
        }
    }
    
    for(int i=0;i<k;i++){
        printf("%d ",intArr[i]);
    }

}

// int* maxMin(int *arr,int lenArr){
//     int* a = (int *)malloc((lenArr)*sizeof(int));
//     int* b = (int *)malloc((lenArr)*sizeof(int));
//     // int j=0;
//     int* w = malloc(sizeof(int));
//     *w=-1;
//     int max = -10001;
//     int freq[10000] = {0};
//     int ac =0;
//     for(int i=0;i<lenArr;i++){
//         if(arr[i]>max){
//             max = arr[i];
//             a[ac] = i;
//             ac++;
//         }
//     }
//     int min = 10001;
//     int bc = 0;
//     // int t = 0;
//     for(int i=lenArr-1;i>=0;i--){
//         if(arr[i]<min){
//             min = arr[i];
//             b[bc] = i;
//             bc++;
//         }
//     }
//     // b[t] = '\0';
//     // a[j] = '\0';
//     // int x = 0;
//     int count = 0;

//     int* c = (int*)malloc((lenArr+1)*sizeof(int));
//     // if(ac< 5000 && bc<5000){
//     // for(int i=0;i<ac;i++){
//     //     for(int k=0;k<bc;k++){
//     //         if(a[i] == b[k]){
//     //             c[count] = a[i];
//     //             count++;
//     //         }
//     //     }
//     // }
//     // }
//     // else{
//         for(int i=0;i<ac;i++){
//             freq[a[i]]++;

//         }
//         for(int j=0;j<bc;j++){
//             freq[b[j]]++;
//         }
//         for(int k=0;k<10000;k++){
//             if(freq[k]==2){
//                 c[count] = k;
//                 count++;
//             }
//         }
//     // }
//     // c[x] = '\0';
//     if(count == 0){
//         return w;
//     }
//     else{
//     for(int f=0;f<count;f++){
//         printf("%d ",c[f]);
//     }
//     }
//     printf("\n");
//     return c;

// }
   

int countCharOccurrences(const char* str, int length, char ch){
    int count = 0;
    for(int i=0;i<length;i++){
        if(str[i] == ch){
            count++;
        }
    }
    // printf("%d\n",count);
    return count;
}

char findFirstNonRepeatingChar(const char* str, int length){
    
    int freq[26];
    for(int i=0;i<26;i++){
        freq[i] = 0;
    } 
   

    int i = 0;
    while(i < length) {
        freq[str[i]-'a']++;
        i++;
    }

    
    for(i=0;i < length;i++) {
        if (freq[str[i]-'a'] == 1) {
            return str[i];
            break;
        }
       
    }
    
    return '&';
    
}

// int *intersection(int *,int *,int ,int);
// int *arr3;
// int len3;
// int *array3;
// int *intersection(int *arr1,int *arr2,int len1,int len2){
	
// 	int count=0;
// 	for(int i=0;i<len1;i++){
// 		for(int j=0;j<len2;j++){
// 			if(arr1[i]==arr2[j]){
// 					count=count+1;	
					
// 				}
				
// 			}
// 		}
	
	
// int temp=0;int temp1=0;
// 	arr3=(int*)malloc(count*sizeof(int));
// 		for(int i=0;i<len1;i++){
// 		for(int j=0;j<len2;j++){
// 			if(arr1[i]==arr2[j]){
// 				temp=0;
// 				for(int k=0;k<count;k++){
// 				if(arr1[i]==arr3[k]){
// 					temp=temp+1;
// 				}
// 					}
// 					if(temp==0){
// 				arr3[temp1]=arr1[i];temp1=temp1+1;
// 					}
// 				}
				
// 			}
// 		}
	
// 	len3=temp1;
// 	array3=(int*)malloc(len3*sizeof(int));
// 	// printf("\n no of common ele:%d\n",len3);
// 	for(int i=0;i<len3;i++){
	
// 	array3[i]=arr3[i];
// 	}
// 	return ((array3));
	
	
// }



char* removeSubstring(char* str, int length, char* sub, int subLength) {
    int i, j, k;
    for (i = 0; i <= length - subLength; i++) {
        for (j = i; j < i + subLength; j++) {
            if (str[j] != sub[j-i]) {
                break;
            }
        }
        if (j == i + subLength) {
            for (k = i; k <= length - subLength; k++) {
                str[k] = str[k + subLength];
            }
            length -= subLength;
            i--;
        }
    }
    
    return str;
}


// void removeSubstring(char* str, int length, char* sub, int subLength) {
//     if (length < subLength) {
//         return ;
//     }
//     if (strncmp(str, sub, subLength) == 0) {
//         memmove(str, str + subLength, length - subLength + 1);
//         removeSubstring(str, length - subLength, sub, subLength);
//     } else {
//         removeSubstring(str + 1, length - 1, sub, subLength);
//     }
// }


int* maxMin(int *arr,int lenArr){
    int* a = (int *)malloc((lenArr)*sizeof(int));
    int* b = (int *)malloc((lenArr)*sizeof(int));
    // int j=0;
    int* w = malloc(sizeof(int));
    *w=-1;
    int max = -1000001;
    int ac =0;
    for(int i=0;i<lenArr;i++){
        if(arr[i]>max){
            max = arr[i];
            a[ac] = i;
            ac++;
        }
    }
    int min = 1000001;
    int bc = 0;
    // int t = 0;
    for(int i=lenArr-1;i>=0;i--){
        if(arr[i]<min){
            min = arr[i];
            b[bc] = i;
            bc++;
        }
    }
    // b[t] = '\0';
    // a[j] = '\0';
    // int x = 0;
    int count = 0;

    int* c = (int*)malloc(lenArr*sizeof(int));
    for(int i=0;i<ac;i++){
        for(int k=0;k<bc;k++){
            if(a[i] == b[k]){
                c[count] = a[i];
                count++;
            }
        }
    }
    // c[x] = '\0';
    if(count == 0){
        return w;
    }
    else{
    for(int f=0;f<count;f++){
        printf("%d ",c[f]);
    }
    }
    printf("\n");
    return c;

}


// void removeSubstring(char *str, int len, char *substr, int sublen) {
//     char *p = str;
//     int i, j, found;

//     while (*p) {
//         found = 0;
//         if (len >= sublen) {
//             for (i = 0, j = 0; i < strlen(p) && j < sublen; i++, j++) {
//                 if (p[i] != substr[j]) {
//                     break;
//                 }
//             }
//             if (j == sublen) {
//                 found = 1;
//                 for (i = 0; i < sublen; i++) {
//                     memmove(p+i, p+i+1, len-(p-str)-i);
//                 }
//             }
//         }
//         if (!found) {
//             p++;
//         } else {
//             len -= sublen;
//         }
//     }
// }


// char* removeSubstring(char *str, int len, char *substr, int sublen) {
//     int i, j, k, found;
//     for (i = 0; i <= len - sublen; i++) {
//         found = 1;
//         for (j = 0; j < sublen; j++) {
//             if (str[i+j] != substr[j]) {
//                 found = 0;
//                 break;
//             }
//         }
//         if (found) {
//             for (k = i; k <= len - sublen; k++) {
//                 str[k] = str[k + sublen];
//             }
//             len = len-sublen;
//             i = i-sublen;
//         }
//     }
//     return str;
// }
