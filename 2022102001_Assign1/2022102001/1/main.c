#include "functions.c"



int main(){
    int u;
    scanf("%d",&u);
     
    for(int a=0;a<u;a++){
        char c[5]; //= (char*)malloc(sizeof(char)*5);
        
        scanf("%s",c);
         

        if(/*c[0] == 'O' && c[1] == 'P' && c[2] == 'E' && c[3] == 'R'*/  c[4] == '1'){
            int n;
            scanf("%d",&n);
            char str[n];
             
            scanf("%s",str);
            reverseString(str,n);
            
            
        }

        else if(/*c[0] == 'O' && c[1] == 'P' && c[2] == 'E' && c[3] == 'R' && */c[4] == '2'){
            int n;
            scanf("%d",&n);
            // 
            char str[n+1];     
            scanf("%s",str);
            
            char* compress = compressString(str,n);
            printf("%s",compress);
            
            free(compress);
            printf("\n");
                
                    
        }
        else if(c[4] == '3'){
            int length;
            scanf("%d",&length);
            int arr[length];
            for(int i= 0;i<length;i++){
                scanf("%d",&arr[i]);
            }
    
            uniqueElements(arr, length);
            
     
            printf("\n");
    

        }
        else if(c[4] == '4'){
            int rows, cols;
            scanf("%d",&rows);
            scanf("%d",&cols);
            int** matrix = (int**) malloc(rows * sizeof(int*)); // allocate memory for transposed matrix
            for (int i = 0; i < rows; i++) {
                matrix[i] = (int*) malloc(cols * sizeof(int));
            }
            for(int i=0;i<rows;i++){
                for(int j=0;j<cols;j++){
                    scanf("%d",&matrix[i][j]);
                }
            }
    
           int** transposed = transpose(matrix, rows, cols);
           for (int i = 0; i < cols; i++) {
                for (int j = 0; j < rows; j++) {
                    printf("%d ", transposed[i][j]);
                }
                printf("\n");
            }
            for(int i=0;i<rows;i++){
                free(matrix[i]);
            }
            for(int i=0;i<cols;i++){
                free(transposed[i]);
            }
            
    
        }
    

    }
}