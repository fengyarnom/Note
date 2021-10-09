#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 50
#define STACK_INCREMENT 10
typedef enum{
    OK,
    STACK_NULL,
}StackReturnStatus;

typedef struct{
    int* top;       //栈顶
    int* base;      //栈底
    int stackSize;  //栈长
}Stack,*StackPtr;

StackReturnStatus
newStuack(StackPtr *stack)
{
    *stack = (StackPtr)malloc(sizeof(Stack));
    (*stack)->base = (int* )malloc(sizeof(int) * STACK_INIT_SIZE);
    (*stack)->top = (*stack)->base;
    (*stack)->stackSize = STACK_INIT_SIZE;

    return OK;
}

StackReturnStatus
push(StackPtr stack,int value)
{
    if(stack->top - stack->base >= stack->stackSize){
        stack->base = (int* ) realloc(stack->base,stack->stackSize + STACK_INCREMENT);
        if(!stack->base){
            exit(0);
        }
        stack->top = stack->base + stack->stackSize;
        stack->stackSize += STACK_INCREMENT;
    }

    *((stack->top)++) = value;
    return OK;
}

StackReturnStatus
pop(StackPtr stack,int* value)
{
    if(stack->top == stack->base){
        return STACK_NULL;
    }
    *value = *(--(stack->top));
    return OK;
}

StackReturnStatus
getTop(StackPtr stack,int *value)
{
    if(stack->base == stack->top){
        return STACK_NULL;
    }
    *value = *(stack->top - 1);
    return OK;
}

StackReturnStatus
stackTraverse(StackPtr stack)
{
    if(stack->top == stack->base){
        return STACK_NULL;
    }else{
        for(int i=0;i < (stack->top - stack->base);i++){
            printf("<%d> ",stack->base[i]);
        }
    }
    return OK;
}



int
main()
{
    StackPtr stack;
    newStuack(&stack);
    push(stack,12);
    push(stack,24);
    int c;
    pop(stack,&c);

    stackTraverse(stack);
    return 0;
}
