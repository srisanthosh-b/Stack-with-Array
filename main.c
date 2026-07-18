#include "header.h"
int main(){
    Stack s=createStack(5);
    push(s,10);
    push(s,20);
    push(s,30);
    display(s);
    int value;
    pop(s,&value);
    display(s);
    pop(s,&value);
    display(s);
    peek(s,&value);
    printf("\n%d",value);
    return 0;
    
}