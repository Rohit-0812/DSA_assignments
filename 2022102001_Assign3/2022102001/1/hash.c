#include "hash.h"

int ascii(char inp){
    
    int s = inp - 97;
    
    return s;
}

int power(int a, int b){
    long long int j = 1;
    for(int i=0;i<b;i++){
        j = (j*a)%TABLESIZE;
    }
    return j;
}

int hashing(char *input){
    int freq[26] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
    long long int k = 1;
    for(int i=0;input[i]!='\0';i++){
        int j = ascii(input[i]);
        k = k*power(freq[j-1],j);
        k = k%TABLESIZE;               
    }
    return k%TABLESIZE;
}

void insert(Hash myHT, char *input, int *freq1){
    int index = hashing(input);
    Node NNode = (Node)malloc(sizeof(struct node));
    strcpy(NNode->data,input);
    for(int i=0;i<26;i++){
        NNode->freq1[i] = freq1[i];
    }
    
    if(myHT->pStart[index] == NULL){
        myHT->pStart[index] = NNode;
        NNode->pNext = NNode;
        NNode->pPrev = NNode;
        
    }
    else{
        NNode->pNext = myHT->pStart[index];
        NNode->pPrev = myHT->pStart[index]->pPrev;
        NNode->pPrev->pNext = NNode;
        myHT->pStart[index]->pPrev = NNode;
    }

}


int check(int *freq1, int *freq){
    
    for(int i=0;i<26;i++){
        if(freq1[i] != freq[i]){
            return 0;
        }
    }
    return 1;
}


void search(char *qry, Hash myHT,int *freq){
    int k = hashing(qry);
    Node dum = myHT->pStart[k];
    int count = 0;
    while(dum != NULL){
        
        
        if(check(dum->freq1,freq) == 1){
            printf("%s ",dum->data);
            count++;
        }
        dum = dum->pNext;
        if(dum == myHT->pStart[k]){
            break;
        }
    }
    if(count == 0){
        printf("-1");
    }
    printf("\n");
}