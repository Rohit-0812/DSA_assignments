#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int xax[] = {-1, 1, 0, 0};
int yax[] = {0, 0, -1, 1};


typedef struct node * Node;
typedef struct que * Que;
struct node{
    int x;
    int y;
    int dist;
};

struct que{
    Node arr;
    int size;
    int cap;
};

Que createQ(int cap)
{
    Que que = (Que)malloc(sizeof(struct que));
    que->arr = (Node)malloc(cap * sizeof(struct node));
    que->size = 0;
    que->cap = cap;
    return que;
}

void swap(Node a, Node b)
{
    struct node temp = *a;
    *a = *b;
    *b = temp;
}

struct node getmin(Que que)
{
    int i = 0, least = 0;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    que->size--;
    struct node minNode = que->arr[0];    
    que->arr[0] = que->arr[que->size];
    

    for (;left < que->size;) {
        if (que->arr[left].dist < que->arr[least].dist) {
            least = left;
        }

        if (right < que->size && que->arr[right].dist < que->arr[least].dist) {
            least = right;
        }

        right = 2 * least + 2;
        left = 2 * least + 1;

        if (least == i) {
            break;
        }
        

        struct node temp = que->arr[i];
        que->arr[i] = que->arr[least];
        que->arr[least] = temp;
        i = least;
    }

    return minNode;
}

void insert(Que que, struct node point) {
    int i = que->size++;
    
    if (i >= que->cap) {
        que->cap = que->cap*2;
        que->arr = realloc(que->arr, que->cap * sizeof(struct node));
    }

    while (i != 0 && que->arr[(i - 1) / 2].dist > point.dist) {
        que->arr[i] = que->arr[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    que->arr[i] = point;
}


void MinimumUsage(Que que, int n, int m, int grid[][1007], int dist[][1007], int visited[][1007]){
    dist[0][0] = 0;
    struct node startNode = {0, 0, 0};
    
    insert(que, startNode);

    while (que->size > 0){
        struct node CurrNode = getmin(que);
        int x = CurrNode.x;
        int y = CurrNode.y;
        if (visited[x][y] != 1){
            visited[x][y] = 1;          
            
            int i = 0;
            while (i < 4) {
                if (x + xax[i] >= 0 && x + xax[i] < n){
                    if( y + yax[i] >= 0 && y + yax[i] < m) {
                        int currentHeight = grid[x][y];
                        int NHeight = grid[x + xax[i]][y + yax[i]];
                        int elevatorUsage;
                        if (currentHeight == NHeight){
                            elevatorUsage = 0;
                        }
                        else{
                            elevatorUsage = 1;
                        }
                        int newdist = dist[x][y] + elevatorUsage;

                        if ((!visited[x + xax[i]][y+yax[i]]) && (newdist < dist[x+xax[i]][y+yax[i]])){
                            
                            dist[x+xax[i]][y+yax[i]] = newdist;
                            struct node NNode = {x+xax[i], y+yax[i], newdist};
                            insert(que, NNode);
                            
                        }
                    }
                }
                i++;
            }
        }
        else{            
            continue;
        }
    }

    printf("%d\n",dist[n-1][m-1]);
}

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        int m;
        scanf("%d %d", &n, &m);

        Que que = createQ(n*m);

        int grid[1007][1007];
        int dist[n][1007];
        int visited[n][1007];

        int i = 0;
        while( i < n){
            int j = 0;
            while( j < m){
                scanf("%d", &grid[i][j]);
                visited[i][j] = 0;
                dist[i][j] = INT_MAX;
                j++;
            }
            i++;
        }
        
        
        
        MinimumUsage(que,n,m,grid,dist,visited);
    }

    return 0;
}