#include <stdio.h>
#include <stdlib.h>

typedef struct Node* tree;
struct Node{
    int data;
    tree left;
    tree right;
};

tree NNode(int val){
    tree temp = (tree)malloc(sizeof(struct Node));
    temp->data = val;
    temp->right = NULL;
    temp->left =NULL;
    return temp;
}

int search(int *arr,int start, int end, int val){
    int i=start;
    while(i<=end){
        if(arr[i] == val){
            return i;
        }
        i++;
    }
}

int val = 0;

tree original(int *preorder, int *inorder, int start, int end){
    
    
    if(start>end){
        return NULL;
    }
    else{
        tree t = NNode(preorder[val++]);
        if(start == end){
            return t;
        }
        else{
            int index = search(inorder,start,end,t->data);
            
            t->left = original(preorder, inorder, start, index-1);
            t->right = original(preorder, inorder, index+1, end);
            
        }
        return t;
    }
        
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

void currdata(tree t,int currlen){
    
    if(t == NULL){
        return;
    }
    else if(currlen == 1){
        printf("%d ",t->data);
    }
    else{
        currdata(t->left, currlen-1);
        currdata(t->right, currlen-1);
    }
}

void levorder(tree t, int h){
   
    for(int i=1;i<=h;i++){
        currdata(t,i);
    }
}

int main(){
    int m;
    scanf("%d",&m);
    while(m){
        int n;
        scanf("%d",&n);
        int preorder[n];
        int inorder[n];
        
        for(int i=0;i<n;i++){
            scanf("%d",&inorder[i]);
        }
        for(int j=0;j<n;j++){
            scanf("%d",&preorder[j]);
        }
        val =0;
        tree t = original(preorder, inorder, 0, n-1);
        int h = height(t);
        levorder(t, h);
        printf("\n");
        m--;
        
    }
}

