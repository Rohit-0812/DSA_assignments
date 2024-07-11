#include "sort.c"

int main(){
    long long int n;
    scanf("%lld",&n);
    
    for(long long int i=0;i<n;i++){
        
        long long int m,k;
        
        scanf("%lld %lld",&m,&k);
        Heap h = Maxheap(m+1);
        for(long long int j=0;j<m;j++){
            long long int a;
            scanf("%lld",&a);
            insert(h,a);
        }
        for(long long int c=0;c<k;c++){
            h = decrement(h);
        }
        printf("%lld\n",h->happiness);
        
    }
}