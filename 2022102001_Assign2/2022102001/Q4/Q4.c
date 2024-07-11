#include <stdio.h>
#include <stdlib.h>


typedef struct Node* tree;
struct Node{
    long long int data;
    tree right;
    tree left;
};

tree NNode(long long int val){
    tree temp = (tree)malloc(sizeof(struct Node));
    temp->data = val;
    temp->right = NULL;
    temp->left =NULL;
    return temp;
}

tree insert(tree t, long long int val){
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
long long int temp = 0;
long long int total = 0;
void modify(tree root) {
    
    if (root != NULL) {
        
        modify(root->left);     
        temp = temp + root->data;
        root->data = temp;
        total = total + temp;
        modify(root->right);
        
    }
}



long long int height(tree t){
    if(t == NULL){
        return 0;
    }
    else{
        long long int left = height(t->left);
        long long int right = height(t->right);
        if(left > right){
            return (left+1);
        }
        else if(right >= left){
            return (right+1);
        }
    }
}

void currdata(tree t,long long int length){
    
    if(t == NULL){
        return;
    }
    else if(length == 1){
        printf("%lld ",t->data);
    }
    else{
        currdata(t->left, length-1);
        currdata(t->right, length-1);
    }
}

void levorder(tree t, long long int h){
    modify(t);
    for(int i=1;i<=h;i++){
        currdata(t,i);
    }
}



tree ListToBST(long long int *arr, long long int len){
    tree t = NULL;
    
    for(int i=0;i<len;i++){
        t = insert(t,arr[i]);
    }
    return t;
    
}


int main(){
    // int = *arr(int*)malloc(sizeof(int)*1000);
    long long int n;
    scanf("%lld",&n);
    long long int arr[n];
    long long int he;
    tree t = (tree)malloc(sizeof(struct Node));
    for(long long int i=0;i<n;i++){
        scanf("%lld",&arr[i]);
    }
    t = ListToBST(arr,n);
    // inorder(t);
    he = height(t);
    // printf("%d\n",he);
    levorder(t,he);
    printf("\n");
    printf("%lld\n",total);
    
    
}