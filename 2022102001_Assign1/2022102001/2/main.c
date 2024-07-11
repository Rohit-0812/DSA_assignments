#include "functions.c"

int main(){
    int u;
    scanf("%d",&u);
    
    for(int a=0;a<u;a++){
        char c[5];

        scanf("%s",c);
        
        if(/*c[0] == 'O' && c[1] == 'P' && c[2] == 'E' && c[3] == 'R' && */c[4] == '1'){
               
	        // int len1,len2;
	           
	        // scanf("%d",&len1);
	             
	        // scanf("%d",&len2);
	        // int *arr1,*arr2;
	        // arr1=(int*)malloc(len1*sizeof(int));
	        // arr2=(int*)malloc(len2*sizeof(int));
	            
	        // for(int i=0;i<len1;i++){
	        //  	scanf("%d",&arr1[i]);
	        // }
		        
		    // for(int i=0;i<len2;i++){
		    //     scanf("%d",&arr2[i]);
	        // }
		       
            // int *ptr=intersection(arr1,arr2,len1,len2);
               
            // for(int i=0;i<len3;i++){
	        //     printf("%d ",*(ptr+i));
            // }

            // printf("\n");
	        int n,m;
            scanf("%d",&n);
            scanf("%d",&m);
            int *a = (int*)malloc(sizeof(int)*n);
            int *b = (int*)malloc(sizeof(int)*m);
            for(int i=0;i<n;i++){
                scanf("%d",&a[i]);
            }
            for(int j=0;j<m;j++){
                scanf("%d",&b[j]);
            }
    
    
            int* s = intersectionArray(a,b,n,m);
            if(*s == -1){
                printf("-1\n");
            }
    
    

    
        }

        else if(c[0] == 'O' && c[1] == 'P' && c[2] == 'E' && c[3] == 'R' && c[4] == '2'){
            int len;
            scanf("%d",&len);
            char str[len];

            char ch;
            getchar();
            for(int i=0;i<len;i++){
                scanf("%c",&str[i]);
            } 
            getchar();           

            scanf("%c",&ch);
            
            int n = countCharOccurrences(str,len, ch);
            printf("%d\n",n);
            
        }
        
        else if(c[0] == 'O' && c[1] == 'P' && c[2] == 'E' && c[3] == 'R' && c[4] == '3'){
            int len;
            scanf("%d",&len);
            char str[len];
            scanf("%s",str);
            char n = findFirstNonRepeatingChar(str,len);
            if(n == '&'){
                printf("-1\n");
            }
            else{
                printf("%c\n",n);
            }
    
        }
        else if(/*c[0] == 'O' && c[1] == 'P' && c[2] == 'E' && c[3] == 'R' && */c[4] == '6'){
            int len,sublen;
            scanf("%d",&len);
            scanf("%d",&sublen);
            char str[len];
            char substr[sublen];
            scanf("%s",str);
            scanf("%s",substr);

            char* st = removeSubstring(str, len, substr, sublen);
            if(*st == NULL){
                printf("-1\n");
            }
            else{
                printf("%s\n", st);
            }
            
            


        }
        else if(/* c[0] == 'O' && c[1] == 'P' && c[2] == 'E' && c[3] == 'R' && */ c[4] == '5'){
            int len;
            scanf("%d",&len);
            int* arr = (int*)malloc(len*sizeof(int));
            for(int i=0;i<len;i++){
                scanf("%d",&arr[i]);
            }
            
            int *s = maxMin(arr,len);
            if (*s == -1){
                printf("-1\n");
            }

    
        }
        // else if(/*c[0] == 'O' && c[1] == 'P' && c[2] == 'E' && c[3] == 'R' &&*/ c[4] == '6'){
        //     int len,sublen;
        //     scanf("%d",&len);
        //     scanf("%d",&sublen);
        //     char str[len];
        //     char substr[sublen];
        //     scanf("%s",str);
        //     scanf("%s",substr);

        //     removeSubstring(str, len, substr, sublen);
        //     printf("%s\n", str);

        // }
    }
}