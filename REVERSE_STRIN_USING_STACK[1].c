#include<stdio.h>
#include<string.h>
#define MAX 20

typedef struct Stack{
    char arr[MAX];
    int top;
}stack;

void intialize(stack *st){
    st->top=-1;
}

void push(stack *st, char c){
    if(st->top==MAX-1){
        printf("Overflow");
    }
    else{
        st->top++;
        st->arr[st->top]=c;
    }
}

char pop(stack *st){
    if(st->top==-1){
        printf("Underflow");
        return -1;
    }
    else{
        char item = st->arr[st->top];
        st->top--;
        return item;
    }
}

void reverse(char *input){
    int length = strlen(input);
    stack st;
    intialize(&st);

    for(int i=0;i<length;i++){
        push(&st,input[i]);
    }

    for(int j=0;j<length;j++){
        input[j]=pop(&st);
    }
}
int main(){
    char input[MAX];
    printf("Enter the string:");
    fgets(input,sizeof(input),stdin);
    input[strcspn(input,"\n")]='\0';

    reverse(input);
    printf("Reversed String: %s \n",input);

    return 0;

}