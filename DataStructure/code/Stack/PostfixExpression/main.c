#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 50
#define STACK_INCREMENT 10

#define INIT_BUFFER_SIZE 100
#define BUFFER_INCREMENT 20
typedef enum{
    OK,
    STACK_NULL,
}ReturnStatus;

typedef struct{
    double* top;       //栈顶
    double* base;      //栈底
    int stackSize;  //栈长
}Stack,*StackPtr;

typedef struct{
    char *buffer;
    int bufferSize;
}InputBuffer,*InputBufferPtr;


ReturnStatus
newStack(StackPtr *stack)
{
    *stack = (StackPtr)malloc(sizeof(Stack));
    (*stack)->base = (double* )malloc(sizeof(double) * STACK_INIT_SIZE);
    (*stack)->top = (*stack)->base;
    (*stack)->stackSize = STACK_INIT_SIZE;

    return OK;
}

ReturnStatus
push(StackPtr stack,double value)
{
    if(stack->top - stack->base >= stack->stackSize){
        stack->base = (double* ) realloc(stack->base,stack->stackSize + STACK_INCREMENT);
        if(!stack->base){
            exit(0);
        }
        stack->top = stack->base + stack->stackSize;
        stack->stackSize += STACK_INCREMENT;
    }

    *((stack->top)++) = value;
    return OK;
}

ReturnStatus
pop(StackPtr stack,double* value)
{
    if(stack->top == stack->base){
        return STACK_NULL;
    }
    *value = *(--(stack->top));
    return OK;
}
ReturnStatus
stackEmpty(StackPtr *stack){
    if((*stack)->top == (*stack)->base){
        return STACK_NULL;
    }
    return OK;
}

ReturnStatus
getTop(StackPtr *stack,double* value){
    if(stackEmpty(stack) == STACK_NULL){
        return STACK_NULL;
    }else{
        *value = *((*stack)->top - 1);
    }

    return OK;
}

ReturnStatus
stackTraverse(StackPtr stack)
{
    if(stack->top == stack->base){
        return STACK_NULL;
    }else{
        printf("\n");
        for(int i=0;i < (stack->top - stack->base);i++){
            printf("<%lf> ",stack->base[i]);
        }
    }
    return OK;
}

ReturnStatus
newInputBuffer(InputBufferPtr *input_buffer){
    *input_buffer = (InputBufferPtr)malloc(sizeof(InputBuffer));
    (*input_buffer)->buffer = NULL;
    (*input_buffer)->bufferSize = INIT_BUFFER_SIZE;
    return OK;
}

void
getLine(char **lineptr, size_t initSize, FILE *stream)
{
    if(*lineptr == NULL){
        *lineptr = (char *)malloc(initSize);

        int counter = 0;
        char c;
        while((c=fgetc(stream)) != '\n'){
            *(*lineptr+counter++) = c;
        }
        *(*lineptr+counter) = '\0';
    }
}

char*
translate(char** buffer)
{
    StackPtr OPTR;
    newStack(&OPTR);

    InputBufferPtr newExpression;
    newInputBuffer(&newExpression);
    newExpression->buffer = (char *)malloc(newExpression->bufferSize);

    char* findPtr = *buffer;
    char* strFindPtr = newExpression->buffer;

    double value;
    while(*findPtr != '\0'){
        if(*findPtr == '('){
            push(OPTR, *findPtr);
        }
        else if(*findPtr == ')'){
            pop(OPTR, &value);
            while (value != '(')
            {
                *strFindPtr++ = value;
                *strFindPtr++ = ' ';
                pop(OPTR, &value);
            }
        }
        else if(*findPtr == '+' || *findPtr == '-'){

            while (stackEmpty(&OPTR) != STACK_NULL){
                getTop(&OPTR,&value);
                if(value == '('){
                    break;
                }else{
                    *strFindPtr++ = value;
                    *strFindPtr++ = ' ';
                    pop(OPTR,&value);
                }
            }
            push(OPTR, *findPtr);

        }
        else if(*findPtr == '*' || *findPtr == '/'){

            while (stackEmpty(&OPTR) != STACK_NULL){
                getTop(&OPTR,&value);
                if(value == '*' || value == '/'){
                    *strFindPtr++ = value;
                    *strFindPtr++ = ' ';
                    pop(OPTR,&value);
                }else{
                    break;
                }
            }
            push(OPTR, *findPtr);
        }
        else if(*findPtr >= '0' && *findPtr <='9'){
            while(*findPtr >= '0' && *findPtr <='9'){
                *strFindPtr++ = *findPtr;
                findPtr++;
            }
            findPtr--;
            *strFindPtr++ = ' ';
        }


        findPtr++;
    }
    //清空残留操作符栈
    while (!stackEmpty(&OPTR))
    {
        pop(OPTR,&value);
        *strFindPtr++ = (char)value;
    }
    *strFindPtr = '\0';
    printf("\n");
    printf("Expression:%s\n",newExpression->buffer);
    return newExpression->buffer;
}
double
calculate(char* expression)
{
    StackPtr OPND;
    newStack(&OPND);
    double leftOpnd,rightOpnd;
    double result;
    char* findPtr = expression;
    while(*findPtr != '\0'){
        if(*findPtr >= '0' && *findPtr <='9'){
            int couter = 0;
            double number = 0;
            char* numberPtr = findPtr;
            while(*numberPtr >= '0' && *numberPtr <='9'){
                couter++;
                numberPtr++;
            }
            for(int i=couter;i>0;i--){
                int tempNumber = 1;
                for(int j=0;j<i-1;j++){
                    tempNumber *= 10;
                }
                number+=(double)(*(findPtr + couter - i) - '0') * tempNumber;
            }
            findPtr += couter;
            push(OPND,number);

        }
        else if(*findPtr == '+'){
            pop(OPND,&rightOpnd);
            pop(OPND,&leftOpnd);
            result = leftOpnd + rightOpnd;
            push(OPND,result);
        }
        else if(*findPtr == '-'){
            pop(OPND,&rightOpnd);
            pop(OPND,&leftOpnd);
            result = leftOpnd - rightOpnd;
            push(OPND,result);
        }
        else if(*findPtr == '*'){
            pop(OPND,&rightOpnd);
            pop(OPND,&leftOpnd);
            result = leftOpnd * rightOpnd;
            push(OPND,result);
        }
        else if(*findPtr == '/'){
            pop(OPND,&rightOpnd);
            pop(OPND,&leftOpnd);
            if(rightOpnd == 0){
                return 1;
            }
            result = leftOpnd / rightOpnd;
            push(OPND,result);
        }

        findPtr++;
    }
    stackTraverse(OPND);
    pop(OPND,&result);
    printf("\nResult:%lf",result);
    return 0;
}
int main() {
    InputBufferPtr inputBuffer;
    newInputBuffer(&inputBuffer);
    getLine(&(inputBuffer->buffer),inputBuffer->bufferSize,stdin);
    calculate(translate(&inputBuffer->buffer));
    return 0;
}
