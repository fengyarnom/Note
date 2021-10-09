//
// Created by yarnom on 9/23/21.
//

#ifndef LINKLIST_LINKLIST_H
#define LINKLIST_LINKLIST_H
#include <stdio.h>
#include <stdlib.h>
typedef struct LNode{
    int data;
    struct LNode* next;
}LNode,*LinkList;

typedef enum{
    OK,             // 状态正常
    OUT_OF_RANGE,   // 访问越界
    LIST_EMPTY,     // 空表错误
}LinkListReturnStatus;

LinkList newLinkList();
LinkListReturnStatus linkListInsert(LinkList headPtr,int location,int data);
LinkListReturnStatus linkListInsertAtEnd(LinkList headPtr,int data);
LinkListReturnStatus linkListInsertAtHead(LinkList headPtr,int data);
LinkListReturnStatus linkListDelete(LinkList headPtr,int location);
int printLinkList(LinkList headPtr);
#endif //LINKLIST_LINKLIST_H
