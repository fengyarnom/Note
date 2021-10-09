#include "inputBuffer.h"

InputBufferPtr
newInputBuffer(){
    InputBufferPtr input_buffer = (InputBufferPtr)malloc(sizeof(InputBuffer));
    input_buffer->buffer = NULL;
    input_buffer->buffer_length = 0;
    input_buffer->buffer_size = INIT_BUFFER_SIZE;

    return input_buffer;
}

void print_prompt(){
    printf(">");
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
        *(*lineptr+counter++) = '\n';
        *(*lineptr+counter) = '\0';
    }
}

int
compareStr(char *str1,char*str2){
    while((*(str1+1) != '\n') && (*str1 == *str2)){
        str1++;
        str2++;
    }

    int size = *str1 - *str2;
    if(size == 0){
        return 0;
    }
    else if(size > 0){
        return 1;
    }
    else{
        return -1;
    }
}


parserReturnStatus
parser(char *str)
{
    if(compareStr(str,"exit") == 0){
        printf("exit!\n");
        return EXIT;
    }
    else if(compareStr(str,"insert") == 0){
        return INSERT;
    }
    else if(compareStr(str,"insert_at_head") == 0){
        return INSERT_AT_HEAD;
    }
    else if(compareStr(str,"insert_at_end") == 0){
        return INSERT_AT_END;
    }
    else if(compareStr(str,"delete") == 0){
        return DELETE;
    }
    else if(compareStr(str,"print_all") == 0){
        return PRINT_ALL;
    }

}

void
router(LinkList headPtr)
{
    while(1){
        print_prompt();
        InputBufferPtr inputBuffer = newInputBuffer();
        getLine(&(inputBuffer->buffer),inputBuffer->buffer_length,stdin);
        parserReturnStatus res = parser(inputBuffer->buffer);
        if(res == EXIT){
            exit(0);
        }
        else if(res == INSERT){
            printf("请输入您需要添加的元素和位置:\n");
            int value,location;
            scanf("%d %d",&value,&location);
            linkListInsert(headPtr,location,value);
            printLinkList(headPtr);
        }
        else if(res == INSERT_AT_HEAD){
            printf("请输入您需要添加的元素\n");
            int value;
            scanf("%d",&value);
            linkListInsertAtHead(headPtr,value);
            printLinkList(headPtr);
        }
        else if(res == INSERT_AT_END){
            printf("请输入您需要添加的元素\n");
            int value;
            scanf("%d",&value);
            linkListInsertAtEnd(headPtr,value);
            printLinkList(headPtr);
        }
        else if(res == PRINT_ALL){
            printLinkList(headPtr);
        }
        else if(res == DELETE){
            printf("请输入您需要删除的位置:\n");
            int location;
            scanf("%d",&location);
            linkListDelete(headPtr,location);
            printLinkList(headPtr);
        }
    }
}





