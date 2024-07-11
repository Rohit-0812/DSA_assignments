#include "bst.c"

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    
    for(int j=0;j<n;j++){
        scanf("%d",&arr[j]);
        
    }
    if(n == 1){
        printf("%d",arr[0]);
    }
    else{
        tree t = ListToBST(arr,n);
        int arr1[n];
        inor(t,arr1);
        for(int j=0;j<n;j++){
            if(arr[j] == arr1[j]){
                swap(arr1,j,n);
            }
        }
        for(int j =0 ; j<n;j++){
            printf("%d ",arr1[j]);
        }
    }
    printf("\n");

    
}