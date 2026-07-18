#ifndef HEADER_H
#define HEADER_H
#include<stdio.h>
#include<stdlib.h>

typedef enum{
    SUCCESS,
    FAILURE
} Status;

struct stack{
    int*StackArray;
    int top;
    int size;
};

typedef struct stack* Stack;

Stack createStack(int);
Status isEmpty(Stack);
Status isFull(Stack);
Status push(Stack, int);
Status pop(Stack, int*);
Status peek(Stack, int*);
Status deleteStack(Stack);
void display(Stack);



#endif