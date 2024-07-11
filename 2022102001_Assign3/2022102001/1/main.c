#include "hash.c"

int main()
{
    int n,m;
    scanf("%d",&n);
    scanf("%d",&m);
    Hash h = (Hash)malloc(sizeof(struct hash));
    h->TABLESIZE = TABLESIZE;
    h->pStart = (Node*)calloc(TABLESIZE, sizeof(Node));
    char *ch = (char *)malloc(sizeof(char)*12);
    char *qu = (char *)malloc(sizeof(char)*12);
    for(int i=0;i<n;i++)
    {
        int *freq1 = (int*)calloc(26,sizeof(int));

        scanf("%s",ch);
        int j = 0;
        while(ch[j]!='\0'){
            freq1[ch[j]-97]++;
            j++;
        }
        insert(h,ch,freq1);
        
        
    }
    for(int i=0;i<m;i++)
    {
        int *freq = (int*)calloc(26,sizeof(int));

        scanf("%s",qu);
        int j = 0;
        while(qu[j]!='\0'){
            freq[qu[j]-97]++;
            j++;
        }

        search(qu,h,freq);
    }
    
}