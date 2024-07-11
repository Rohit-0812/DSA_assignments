#include "sort.c"

int main(){
    int n;
    scanf("%d",&n);

    while(n--){
        int k,m;
        int sch;
        scanf("%d%d",&k,&m);
        int data[k][m];
        for (int i=0;i<m;i++){
            int a = 0;
            while(a<k){
                scanf("%d",&data[a][i]);
                a++;
            }
        }
        scanf("%d",&sch);
        int index = sch-1;
        
        int count = 0;
        int sels[m];
        int sc[m];
        for(int i=0;i<m;i++){
            sels[i] = data[index][i];
        }
        insert(sels,m);
        
        
        for(int i=0;i<m;i++){       
            int* max = (int *)malloc(sizeof(int)*(k));
            for(int l=0;l<k;l++){
                if(l == index){
                    
                    continue;
                }                
                max[l] = data[l][i];
                
            }
            
            insert(max,k);
            sc[i] = max[0];            
        }
        insert(sc,m);
        
        for(int i=0;i<m;i++){
            if(sc[i] < sels[count]){
                count++;
            }
        }
        printf("%d\n",count);
    } 

}