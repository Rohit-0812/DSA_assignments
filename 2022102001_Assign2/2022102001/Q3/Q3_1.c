#include <stdio.h>
#include <stdlib.h>

typedef struct Node* tree;
struct Node{
    int data;
    tree right;
    tree left;
};

tree NNode(int val){
    tree temp = (tree)malloc(sizeof(struct Node));
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

int height(tree t){
    if(t == NULL){
        return 0;
    }
    else{
        int left = height(t->left);
        int right = height(t->right);
        if(left > right){
            return (left+1);
        }
        else if(right >= left){
            return (right+1);
        }
    }
}

void oddata(tree t,int length){
    if(t == NULL){
        return;
    }
    else if(length == 1){
        printf("%d ",t->data);
    }
    else{
        oddata(t->right, length-1);
        oddata(t->left, length-1);
    }
}

void currdata(tree t,int length){
    if(t == NULL){
        return;
    }
    else if(length == 1){
        printf("%d ",t->data);
    }
    else{
        currdata(t->left, length-1);
        currdata(t->right, length-1);
    }
    
    
}


void relevorder(tree t, int h){
    
    for(int i=1;i<=h;i++){
        if(i%2 != 0){
            currdata(t,i);
        }
        else if(i%2 == 0){
            oddata(t,i);
        }
    }
}



tree ListToBST(int *arr, int len){
    tree t = NULL;
    
    for(int i=0;i<len;i++){
        t = insert(t,arr[i]);
    }
    return t;
    
}


int main(){
    
    int n,m;
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d",&n);
        int arr[n];
        int len;
        tree t = (tree)malloc(sizeof(struct Node));
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        t = ListToBST(arr,n);
        len = height(t);
        relevorder(t,len);
        printf("\n");
    }
    
    
}