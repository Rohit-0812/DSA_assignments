#include "functions.h"



char presence(char c[]){
    int count = 0;
    char j = '&';   
    char k = '*';
    for(int i=0;c[i]!='\0';i++){
        if(c[i]=='(' || c[i]=='[' || c[i]=='{'){
            count++;
        }
        
    }
    if(count != 0){
        return j;
    }   
    else {
        return k;
    }
}

void push(struct Node** top,char ch){
    struct Node* Nnode = (struct Node*)malloc(sizeof(struct Node));
    Nnode->data = ch;
    Nnode->next = (*top);
    (*top) = Nnode;
}

char pop(struct Node** top){
    char residue;
    struct Node* roof;

    roof = *top;
    residue = roof->data;
    *top = roof->next;
    free(roof);
    return residue;
}

int check(char c1,char c2){
    if ((c1 == '(' && c2 == ')') || (c1 == '{' && c2 == '}') || (c1 == '[' && c2 == ']')){
		return 1;
    }
	
	else{
		return 0;
    }

}

int balance(char c[]){
    struct Node* stack = NULL;
    char ch = presence(c);
    if(ch == '&'){
        for(int i=0; c[i]!='\0'; i++){
            if(c[i]=='(' || c[i]=='[' || c[i]=='{'){
                push(&stack,c[i]);
            }
            if(c[i]==']' || c[i]=='}' || c[i]==')'){
                if(stack == NULL){
                    return 0;
                }
                else if (!check(pop(&stack),c[i])){
		            return 0;
                }
            }
        }
        if(stack == NULL){
            return 1;
        }
        else{
            return 0;
        }
    }
    else if(ch == '*'){
        return 0;
    }
}

int strlength(char c[]){
    int count = 0;
    for(int i=0; c[i]!='\0'; i++){
        count++;
    }
    return count;
}

