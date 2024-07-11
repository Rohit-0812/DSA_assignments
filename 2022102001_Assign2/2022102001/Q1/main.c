#include "functions.c"

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        char c[10000];
        int len;
        scanf("%s",c);
        
        len =  strlength(c);
        
        int count = 0;
       
        for(int i=0;i<len/2;i++){
            
            if(c[i] == c[(len-1)-i]){
                count++;
            }
            
        }
        if(balance(c)){
            printf("Balanced\n");
        }
        
        
        else if(count == (len/2)){
            printf("Palindromic\n");

        }
        else if(balance(c) && count == (len/2))
        {
            printf("Balanced and Palindromic\n");
        }
        else if(balance(c) == 0 && count != (len/2)){
            printf("-1\n");
        }
      
    }
}
