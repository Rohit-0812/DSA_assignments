#include "sort.c"

int main(){
    long long int n;
    scanf("%lld",&n);
    for(long long int i=0;i<n;i++){
        long long int m;
        scanf("%lld",&m);
        long long int a[m];
        long long int b[m];
        long long int ind[m];
        long long int j2[m];
        for(long long int j=0;j<m;j++){
            ind[j] = j;
            scanf("%lld",&a[j]);
        }
        for(long long int j=0;j<m;j++){
            scanf("%lld",&b[j]);
        }
        insert(a,m,ind,b);        
        
        compare(j2, a, b, m);
        
        printf("%lld %lld\n",a[m-1],j2[m-1]);

    }
}