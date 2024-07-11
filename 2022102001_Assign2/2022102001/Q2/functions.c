#include "functions.h"

void push(Queue Head, int val){

    Queue temp = (Queue)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = Head;
    end->next = temp;
    end = end->next;
    
    
}

void Inject(Queue front, int val){
    if(front->next == NULL || front->next == front || front == end){
        Queue temp = (Queue)malloc(sizeof(struct Node));
        temp->data = val;
        temp->next = front;
        end->next = temp;
        end = end->next;
        
        return;
        // end = front;
    }
    // else{
    Queue temp = (Queue)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = front->next;
    front->next = temp;
        // front = temp;
        // front = front->next;
        // end->next = front;        
    // }
    
    // free(temp);
}

int Pop(Queue Head){
    int x = -1;
    if(Head->next == NULL || Head == end){
        return x;
    }
    else if(Head->next == Head){
        return x;
    }
    else{
        if(Head->next->next==Head){
            end = Head;
        }
        int y;
        y = Head->next->data;
        Head->next = Head->next->next;
        return y;
        
        
    }
    
}

int popRear(Queue front){
    int x = -1;
    Queue temp = front;
    if(front->next == front || front == NULL || front->next == NULL){   
        return x;
    }
    Queue prev = temp;
    while(temp->next!=front)
    {
        prev = temp;
        temp = temp->next;
    }
    x = temp->data;
    end = prev;
    prev->next = front;
    free(temp);
    return x;
    
}

void Print(Queue front){
    // int count = 0;
    if(front->next == front || front == end || front == NULL){
        printf("-1");
    }
    Queue te = front->next;
    
    while(te != front){
        printf("%d ",te->data);
        te = te->next;
    }
    printf("\n");
}

void PrintReverse(Queue front){
    if(front == end || front->next == front){
        printf("-1");
    }
    else{
        int *arr = malloc(sizeof(int)*10000);
        Queue te = front->next;
        int i=0;
        while(te != front){
            arr[i] = te->data;
            te = te->next;
            i++;
        }
        
        for(int j=i-1;j>=0;j--){
            printf("%d ",arr[j]);
        }
    }
    printf("\n");
   
}

int findElem(Queue front,int pos){
    int count =0;
    Queue temp = front;
    Queue te = front;
    if(front->next == front || front == NULL || front == end){
        printf("-1\n");
    }
    else{
        
        while(te->next != front){
            count++;
            te = te->next;
        }
        
        for(int i=0;i<pos;i++){
            temp = temp->next;
            
        }
        if(count < pos){
            printf("-1\n");
        }
        else{
            printf("%d\n",temp->data);
        }
    }
    
   
}

void removeKElems(Queue front,int k){
    
    if(front->next == front || front == end || front == NULL){
        front->next = front;

        
    }
    
    else{
        Queue temp = front;
        int count = 0;
        temp = temp->next;
        while(temp != front){
            temp = temp->next;
            count++;
        }
        if(k>=count){
            front->next = front ;
        }
        else if(k<count){
            for(int i=0;i<k;i++){
                front->next = front->next->next;
            } 
        }
        if(front->next==front){
            end = front;
        }
    }

}
