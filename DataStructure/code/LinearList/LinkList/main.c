#include <stdio.h>
#include <stdlib.h>
#include "linkList.h"
#include "inputBuffer.h"

int
main()
{
    LinkList headPtr = newLinkList();
//    linkListInsert(headPtr,1,23);
//    linkListInsert(headPtr,1,45);
//    linkListInsertAtEnd(headPtr,25);
//    printLinkList(headPtr);

    router(headPtr);



//    int num = 0;
//    int temp = 0;

//    printf("请输入需要添加元素的个数:");
//    scanf("%d",&num);
//    printf("请输入您需要添加的元素:\n");
//    for(int i=0;i<num;i++){
//        scanf("%d",&temp);
//        linkListInsertAtHead(headPtr,temp);
//    }
//
//    printf("目前链表中存在以下元素:\n");
//    printLinkList(headPtr);
//
//    printf("请输入您需要删除的元素位置:\n");
//    scanf("%d",&temp);
//    linkListDelete(headPtr,temp);
//    printf("目前链表中存在以下元素:\n");
//    printLinkList(headPtr);


    return 0;
}
