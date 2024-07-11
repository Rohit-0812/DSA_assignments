#include "sort.c"

int main(){
    int n;
    scanf("%d",&n);
    for(int j=0;j<n;j++){
        int m;

        scanf("%d",&m);
        char** input = (char**)malloc((m+1)*sizeof(char*));
        int length[m];
        for(int i=0;i<m;i++){
            scanf("%d", &length[i]);
            input[i] = (char *)malloc((length[i]+1)*sizeof(char));
            scanf("%s", input[i]);
        }
        Sort(input,m,length);

        for (int i = m-1; i >= 0; i--){
            printf("%s\n", input[i]);
            
        }

    }
}