#include "hash.h"

int isPalindrome(char *inp, int a, int b){
    
    if(inp[a] != inp[b]){
        return 0;
    }
    return 1;
}

int mid(char *a, int index){
    
    int l = index;
    int r = index;
    int n = strlen(a);
    int count = -1;
    while(isPalindrome(a,l,r)){
        count++;
        l--;
        r++;
        if(l<0 || r>n-1){
            break;
        }
            
            
    }
    return count+1;
    

}

void check(int l, int r, int *val, char *org2){
    l--;
    r--;
    int l1 = 2*l+1;
    int r1 = 2*r+1;

    int c = (l1+r1)/2;
    int len = r-l+1;

    if(!val[c]){
        val[c] = mid(org2,c);
    }

    if(len<val[c]){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}
