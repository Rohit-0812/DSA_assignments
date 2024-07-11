#include "heap.c"

int main() {
    
    Heap h = Minheap(10000001);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int a;
        scanf("%d",&a);
        h = insert(h,a);
        if(h->sum < 0){
            h = rem_top(h);
        }
        
    }
   
    printf("%d\n",h->size);
}