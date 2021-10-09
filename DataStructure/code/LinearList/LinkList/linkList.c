#include "linkList.h"


//实例化一个头指针，用其代表整个链表。
LinkList
newLinkList()
{
    LinkList headPtr = (LinkList)malloc(sizeof(LNode));
    headPtr->data = 0;
    headPtr->next = NULL;
    // 返回生成的实例化头指针
    return headPtr;
}

LinkListReturnStatus
linkListInsert(LinkList headPtr,int location,int data)
{
    int counter = 1;
    LinkList findPtr = headPtr;

    while(findPtr->next && counter++ < location){
        findPtr = findPtr->next;
    }

    LinkList newNode = (LinkList)malloc(sizeof(LNode));
    newNode->data = data;
    newNode->next = findPtr->next;
    findPtr->next = newNode;

    return OK;
}
LinkListReturnStatus
linkListInsertAtEnd(LinkList headPtr,int data)
{
    int counter = 1;
    LinkList findPtr = headPtr;
    // 若 findPtr == NULL ，counter == 1 是为空链表，
    // findPtr ！= NULL 与 counter=1 互斥
    while(findPtr->next){
        findPtr = findPtr->next;
    }
    LinkList newNode = (LinkList)malloc(sizeof(LNode));
    newNode->data = data;
    newNode->next = findPtr->next;
    findPtr->next = newNode;

    return OK;
}
LinkListReturnStatus
linkListInsertAtHead(LinkList headPtr,int data)
{
    linkListInsert(headPtr,1,data);
    return OK;
}

LinkListReturnStatus
linkListDelete(LinkList headPtr,int location)
{
    if(location <= 0){
        return OUT_OF_RANGE;
    }
    if(headPtr == NULL){
        printf("ERROR:This LinkList is NULL\n");
        return LIST_EMPTY;
    }
    int counter = 1;
    LinkList findPtr = headPtr;
    //找到指定节点 的 上一个节点
    while(findPtr->next && counter++ < location){
        findPtr = findPtr->next;
    }
    // 判断指定节点的next是否指向空节点，
    // 若是则把前一个节点的next指向NULL，
    // 若不是，则把前一个节点的next指定节点指定节点 的后一个节点
    LinkList temp = findPtr->next;
    if(findPtr->next->next){
        findPtr->next = findPtr->next->next;
    }else{
        findPtr->next = NULL;
    }
    free(temp);

    return 0;
}

int
printLinkList(LinkList headPtr)
{
    printf("目前的链表元素：");
    if(headPtr->next == NULL){
        printf("<null>");
    }else{
        LinkList findPtr = headPtr->next;
        while(findPtr){
            printf("<%d> ",findPtr->data);
            findPtr = findPtr->next;
        }
    }
    printf("\n");
    return 0;
}

