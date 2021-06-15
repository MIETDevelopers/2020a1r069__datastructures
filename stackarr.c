#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int *arr;
    int size;
    int top;
};
int push(struct Stack *stack, int value){
    if (stack->size == 0){
        stack->arr = (int *)malloc(sizeof(int));
    }else{
        stack->arr = (int *)realloc(stack->arr,(((stack->size)+1)*sizeof(int)));
    }
    (stack->size)++;
    *(stack->arr + ((stack->size)-1)) = value;
    printf("pushing stack: %d\n" , value);
    return stack->size;
}
int topOfStack(struct Stack *stack){
    return *(stack->arr + ((stack->size)-1));
}
int pop(struct Stack *stack){
     int top = topOfStack(stack);
     printf("the stack %d is popped\n", top);
     (stack->size)--;
     return top;
}
int main(){
    struct Stack stackA;
    stackA.size = 0;
    push(&stackA,20);
    push(&stackA,48);
    push(&stackA,40);
    push(&stackA,70);
    push(&stackA,60);
    push(&stackA,80);
    pop(&stackA);
    printf("top of the stack: %d\n", topOfStack(&stackA));
    printf("popped the stack: %d\n" , pop(&stackA));
    printf("after poping the stack top: %d\n", topOfStack(&stackA));  
    return 0;
}
