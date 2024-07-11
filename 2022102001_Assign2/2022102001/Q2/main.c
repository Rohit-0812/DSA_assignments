#include "functions.c"

int main(){
    int n;
    scanf("%d",&n);


    Queue Head = (Queue)malloc(sizeof(struct Node));
    Head->next = Head;
    end = Head;
    for(int i=0;i<n;i++){
        char c[6];
        scanf("%s",c);
       if(c[4] == '1'){
            int d;
            scanf("%d", &d);
            push(Head,d);
        }
        else if(c[4] == '2'){
            int k;
            k = Pop(Head);
            printf("%d\n",k);
        }
        else if(c[4] == '3'){
            int d;
            scanf("%d",&d);
            Inject(Head,d);
        }
        else if(c[4] == '4'){
            int k;
            k = popRear(Head);
            printf("%d\n",k);
        }
        else if(c[4] == '5'){
            Print(Head);
        }
        else if(c[4] == '6'){
            PrintReverse(Head);
        }
        else if(c[4] == '7'){
            int k;
            scanf("%d",&k);
            findElem(Head,k);
        }
        else if(c[4] == '8'){
            int k;
            scanf("%d",&k);
            removeKElems(Head,k);
        }
    }
}