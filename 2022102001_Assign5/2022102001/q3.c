#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct stGraph* Graph;


int* arr;
int* patch;


struct stGraph{
    int x;
    int y;
    int fert;    
};


Graph crGraph(int x, int y, int R);

void TotalProfit(Graph G, int Index, int *Profit){
    

    if(arr[Index] == 0){
        return;
    }
    if( arr[Index] == 2 ){
        return;
    }

    int CurrRow = Index/(G->y);
    int CurrCol = Index%(G->y);

    if(!((CurrRow < G->x && CurrRow >= 0) && (CurrCol < G->y && CurrCol >= 0))){
        return;
    }
    
    arr[Index] = 2;

    int rowTop = CurrRow+1, rowBottom = CurrRow-1;
    int colLeft = CurrCol-1, colRight = CurrCol+1;
    

    int currNumAdj = (rowTop*G->y) + CurrCol;


    
    if((rowTop < G->x && rowTop >= 0) && (CurrCol < G->y && CurrCol >= 0)){
        if(arr[currNumAdj]){
            (*Profit) = (*Profit) + 1;

            if(arr[currNumAdj]==2){
                
            }
            else{
                TotalProfit(G,currNumAdj, Profit);
            }
        }
    }

    
    if((rowBottom < G->x && rowBottom >= 0) && (CurrCol < G->y && CurrCol >= 0)){
        currNumAdj = (rowBottom*G->y) + CurrCol; 
        if (arr[currNumAdj]){
            (*Profit) = (*Profit) + 1;

            if(arr[currNumAdj]==2){
                
            }
            else{
                TotalProfit(G,currNumAdj, Profit);
            }
        }
    }

     
    if((CurrRow <G->x && CurrRow >=0) && (colLeft < G->y && colLeft >= 0)){
        currNumAdj = (CurrRow*G->y) + colLeft;
        if(arr[currNumAdj]){
            (*Profit) = (*Profit) + 1;

            if(arr[currNumAdj]==2){
                
            }
            else{
                TotalProfit(G,currNumAdj, Profit);
            }
        }
    }
    
    
    if((CurrRow <G->x && CurrRow >=0) && (colRight < G->y && colRight >= 0)){
        currNumAdj = (CurrRow*G->y) + colRight; 
        if(arr[currNumAdj]){
            (*Profit) = (*Profit) + 1;

            if(arr[currNumAdj]==2){
                
            }
            else{
                TotalProfit(G,currNumAdj, Profit);
            }
        }
    }
}
Graph crGraph(int x, int y, int R){
    Graph G = (Graph)malloc(sizeof(Graph));    
    int mul = x*y;    
    G->x = x;
    G->y = y;
    G->fert = R;
    patch = (int *)malloc(R*sizeof(int));
    arr = (int*)calloc(mul,sizeof(int));
    return G;
}



int main()
{
    int n;
    int m;
    int r;
    int a,b;
    scanf("%d %d",&n,&m);
    scanf("%d",&r);

    Graph G = crGraph(n,m,r);

    
    int j =0;
    while(j<r){
        scanf("%d",&a);
        scanf("%d",&b);
        patch[j] = ((a-1)*(G->y) + (b-1));
        arr[patch[j]] = 1;
        j++;
    }

    int maxProfit = 0;

    int i =0;
    while(i < G->fert){
        int Profit = 0;
        if(arr[patch[i]]!=2){
            TotalProfit(G,patch[i], &Profit);
        }
        if(Profit>maxProfit){
            maxProfit = Profit;
        }
        i++;
    }

    printf("%d\n",maxProfit);

    
    return 0;
}