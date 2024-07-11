#include "hash.c"

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    char org[n];
    char org2[2*n+1];
    
    scanf("%s",org);
    for(int i=0;i<2*n+1;i++){
        if(i%2 == 0 ){
            org2[i] = '#';
        }
        if(i%2 != 0){
            org2[i] = org[(i-1)/2];
        }
    }


    int *val = (int*)calloc(2*n+1,sizeof(int));

    int l,r;
    for(int i=0;i<m;i++){
        scanf("%d %d",&l,&r);
        check(l,r,val,org2);
    }
   
}
