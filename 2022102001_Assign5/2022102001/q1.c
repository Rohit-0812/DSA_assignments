#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXN 100001

typedef struct node * Node;
typedef struct graph * Graph;
typedef struct heap * Heap;

struct heap {
    int* arr;
    int size;
    int capacity;
    
};

struct node {
    int p;
    Node next;
};

struct graph {
    int V;
    Node* adjList;
};



int visit[MAXN];
int minim[MAXN];
int idx;


Graph createGraph(int V) {
    Graph NGraph = (Graph)malloc(sizeof(struct graph));
    NGraph->adjList = (Node*)calloc(V , sizeof(Node));
    NGraph->V = V;
    return NGraph;
}

Heap Minheap(int capacity) {
    Heap h = (Heap) calloc (1, sizeof(struct heap));
    h->arr = (int*) calloc (capacity, sizeof(int));
    h->capacity = capacity;
    h->size = 0;
    return h;
}

void addEdge(Graph g, int src, int p) {
    Node NNodeFront = (Node)malloc(sizeof(struct node));
    NNodeFront->p = p;
    NNodeFront->next = g->adjList[src];
    g->adjList[src] = NNodeFront;

    Node NNodeBack = (Node)malloc(sizeof(struct node));
    NNodeBack->p = src;
    NNodeBack->next = g->adjList[p];
    g->adjList[p] = NNodeBack;
}


void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

Heap heapify(Heap h, int index) {
    if (h->size <= 1)
        return h;
    
    int left = 2*index + 1; 
    int right = 2*index + 2;     


    int least = index; 


    if (left < h->size && (h->arr[index] > h->arr[left])){
        
        least = left; 
     
    }

    
    if (right < h->size ){
        if(h->arr[least] > h->arr[right]){
            least = right; 
        }
    }

    
    if (least != index) 
    { 
        swap(&h->arr[index],&h->arr[least]);
        h = heapify(h, least); 
    }

    return h;
}



Heap insert(Heap h, int element) {

    h->size++;
    h->arr[h->size - 1] = element;
    
    int curr = h->size - 1;
    
    while (curr > 0 && h->arr[(curr-1)/2] > h->arr[curr]) {
        
        int temp = h->arr[(curr-1)/2];
        h->arr[(curr-1)/2] = h->arr[curr];
        h->arr[curr] = temp;
        
        curr = (curr-1)/2;
        h = heapify(h,h->size);
    }
    return h; 
}


int getmin(Heap h) {
    h->size--;
    int min = h->arr[0];    
    h->arr[0] = h->arr[h->size];
    heapify(h, 0);
    return min;
}

void travel(Graph g, int u, Heap h) {
    visit[u] = 1;
    insert(h, u);

    for(;h->size>0;) {
        int v = getmin(h);
        minim[idx] = v+1;
        idx+=1;

        Node n = g->adjList[v];
        for(;n!=NULL;) {
            if (visit[n->p]==1) {
                n=n->next; 
                continue;
            }

            
            insert(h, n->p);
            visit[n->p] = 1;
            n = n->next;
            
           
        }
    }
}

int main() {
    int n, m;

    scanf("%d", &n);

    Heap h = Minheap(n);
    Graph g = createGraph(n);

    scanf("%d", &m);

    while(m--){
        int u, v;
        scanf("%d",&u);
        scanf("%d",&v);
        addEdge(g, u-1, v-1);
    }

    travel(g, 0, h);

    for(int i=0;i<n;i++){
        printf("%d ", minim[i]);
    }
    printf("\n");
    
}