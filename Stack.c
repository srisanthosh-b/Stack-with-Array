#include "header.h"

Stack createStack(int size) {
    Stack new = (Stack)malloc(sizeof(struct stack));
    if (new == NULL) {
        printf("\nMemory allocation failed\n");
        return NULL;
    }
    new->StackArray = (int*)malloc(size * sizeof(int));
    if (new->StackArray == NULL) {
        printf("\nMemory allocation for stack array failed\n");
        free(new);
        return NULL;
    }
    new->top = -1;
    new->size = size;
    for(int i=0;i<size;i++){
        new->StackArray[i]=0;
    }
    printf("\nStack created with size %d\n", size);
    return new;
}

Status isEmpty(Stack s){
    return (s->top == -1) ? SUCCESS : FAILURE;
}

Status isFull(Stack s){
    return (s->top == s->size-1) ? SUCCESS : FAILURE;
}

Status push(Stack s, int value){
    if(isFull(s) == SUCCESS){
        printf("\nStack Overflow: Cannot push the element\n");
        return FAILURE;
    }
    s->StackArray[++(s->top)]=value;
    printf("\nElement Added to Stack\n");
    return SUCCESS;
}

Status pop(Stack s,int*value){
    if(isEmpty(s)==SUCCESS){
        printf("\nStack Underflow: Cannot pop the element\n");
        return FAILURE;
    }
    *value=s->StackArray[(s->top)];
    s->StackArray[(s->top)--]=0;
    printf("\nElement Removed from Stack\n");
    return SUCCESS;
}

Status peek(Stack s,int*value){
    if(isEmpty(s)==SUCCESS){
        printf("\nStack is empty: Cannot peek the element\n");
        return FAILURE;
    }
    *value=s->StackArray[s->top];
    return SUCCESS;
}

Status deleteStack(Stack s){
    if(s==NULL){
        printf("\nStack is already deleted or not created\n");
        return FAILURE;
    }
    free(s->StackArray);
    free(s);
    printf("\nStack deleted successfully\n");
    return SUCCESS;
}

void display(Stack s){
    if(isEmpty(s)==SUCCESS){
        printf("\nStack is empty\n");
    } else {
        printf("\nStack elements: \n");
        for(int i = 0; i < s->top; i++){
            printf("\n %d", s->StackArray[i]);
            printf("\n |");
        }
        printf("\n %d",s->StackArray[s->size-1]);
    }
}