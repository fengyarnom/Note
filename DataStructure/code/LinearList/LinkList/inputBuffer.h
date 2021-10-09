//
// Created by yarnom on 9/21/21.
//

#ifndef LINKLIST_INPUTBUFFER_H
#define LINKLIST_INPUTBUFFER_H
#include <stdio.h>
#include <stdlib.h>
#include "linkList.h"
#define INIT_BUFFER_SIZE 100
#define BUFFER_INCREASE_SIZE 20

typedef struct{
    char *buffer;
    int buffer_length;
    int buffer_size;
}InputBuffer,*InputBufferPtr;

typedef enum {
    EXIT,
    INSERT,
    INSERT_AT_HEAD,
    INSERT_AT_END,
    DELETE,
    PRINT_ALL
}parserReturnStatus;

InputBufferPtr newInputBuffer();
void getLine();
void router(LinkList headPtr);
parserReturnStatus parser(char *str);
#endif //LINKLIST_INPUTBUFFER_H
