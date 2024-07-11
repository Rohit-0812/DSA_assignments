#include "functions.c"
int main()
{
    int n,i;
    struct Node * Head = (struct Node * )malloc(sizeof(struct Node));
    Head-> next = Head;
    scanf("%d",&n);
    for(i = 0; i < n ; i++)
    {
        char A[5];
        scanf("%s",A);
        if(A[4] == '1')
        {
            int n;
            scanf("%d",&n);
            Insert(Head,n);
        }
        else if(A[4] == '2')
        {
            int num;
            scanf("%d",&num);
            struct Node * ptr = Find(Head,num),*qtr = Head-> next;
            while(ptr != NULL && qtr-> next != ptr)
            {
                qtr = qtr-> next;
            }
            if(ptr)
            {
                qtr-> next = qtr-> next-> next;
                ptr-> next = Head-> next;
                Head-> next = ptr;
                // ptr-> next = Head;
                // qtr = Head-> next;
                // while(qtr-> next != Head)
                //     qtr = qtr-> next;
                // qtr-> next = ptr;
                // Head-> next = ptr;
            }

        }
        else if(A[4] == '3')
        {
            Print(Head);
        }
        else
            printf("Invalid Input...\n");
    }
    return 0;
}