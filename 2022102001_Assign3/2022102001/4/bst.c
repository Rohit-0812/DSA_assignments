#include "bst.h"

tree NNode(int val){
    tree temp = (tree)malloc(sizeof(struct node));
    temp->data = val;
    temp->right = NULL;
    temp->left =NULL;
    return temp;
}

tree insert(tree t, int val){
    if(t == NULL){
        return NNode(val);
    }
    if(val < t->data){
        t->left = insert(t->left,val);
    }
    else if(val > t->data){
        t->right = insert(t->right,val);
    }
    return t;
}


void inor(tree t, int *arr){
    
    if(t != NULL){
        
        inor(t->left,arr);
        a++;
        arr[a] = t->data;
        
        inor(t->right,arr);
        
        
    }
}

tree ListToBST(int *arr, int len){
    tree t = NULL;
    
    for(int i=0;i<len;i++){
        t = insert(t,arr[i]);
    }
    return t;
    
}


void swap(int *arr,int j, int n){
    if(j<n-1){
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
    }
    else{
        int temp = arr[j];
        arr[j] = arr[j-1];
        arr[j-1] = temp;
    }
}
