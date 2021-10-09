#include <stdio.h>
#include <stdlib.h>

#define LIST_INIT_SIZE 2  //初始化列表长度
#define LIST_EXPAND_SIZE 20 //扩展长度
typedef struct {
    int *elem;      //基地址
    int length;     //当前长度
    int listSize;   //当前分配总长度
}SqList;

SqList* initList_sq(SqList *L){
    // 分配连续的内存空间给基地址
    L->elem = (int*)malloc(LIST_INIT_SIZE * sizeof(int));
    // 初始化长度为0
    L->length = 0;
    L->listSize = LIST_INIT_SIZE;
    return L;
}
//在此定义一个结构体，*elem作为整个数组的基地址，而 length 作为数组的实际长度，没有赋值的区域用length判断限制，避免越界。

int listExpand_sq(SqList *L){
    int* newElemBase = (int*) realloc(L->elem,L->listSize+(LIST_EXPAND_SIZE * sizeof(int)));
    if(newElemBase != NULL){
        L->elem = newElemBase;
        L->listSize += LIST_EXPAND_SIZE;
        return 0;
    }else{
        printf("列表扩展失败，内存不足");
        return 1;
    }
}
// 这是List的扩展函数，当length <= listSize 时，我们就应当给整个数组扩容，使用的是realloc方法
// realloc 的描述如下：
// The C library function void *realloc(void *ptr, size_t size) attempts to resize the memory block pointed to by ptr that was previously allocated with a call to malloc or calloc.
// 它可以重新调整ptr指针指向的内存块大小，
// The function may move the memory block to a new location (whose address is returned by the function).
// 但是值得注意的是，原理是 将旧内存块移动到一块新的内存块中，大小根据 size 重新调整
int listPush_sq(SqList *L,int value){
    // 防止溢出
    if(L->length>=L->listSize){
        int res = listExpand_sq(L);
        if(res){
            return 1;
        }
    }
    //在链表末尾追加元素
    L->elem[L->length] = value;
    L->length += 1;
    return L->elem[L->length-1];
}
int listInsert_sq(SqList *L,int location,int value){
    // 防止溢出
    if(location<1 && location > L->length+1){
        return 1;
    }
    if(L->length>=L->listSize){
        if(listExpand_sq(L)){
            return 1;
        }
    }
    //插入操作
    int* q = &(L->elem[location-1]); // q指向插入位置
    //插入位置往后元素，全体往后一个单位。
    for(int* p = &(L->elem[L->length-1]); p>=q;--p){
        *(p+1) = *p;
    }
    *q = value;
    //list长度加1
    L->length += 1;
    return 0;
}
int listDelete_sq(SqList *L,int location){
    if((location < 1) || (location > L->length)){
        return 1;
    }
    // p为指定删除地址
    int* p = &(L->elem[location - 1]);
    // q为末尾元素地址
    int* q = &(L->elem[L->length-1]);
    for(p+1;p<=q;p++){
        *(p-1) = *p;
    }
    L->length -= 1;
    return 0;
}
int getElem_sq(SqList *L,int loacation){
    if(loacation>=1 && loacation<=L->length){
        return L->elem[loacation-1];
    }else{
        printf("!!查询越界\n");
        return 0;
    }
}
int printList_sq(SqList *L){
    for(int* p=L->elem;p<=&(L->elem[L->length-1]);p++){
        printf("%d ",*p);
    }
    printf("\n");
    return 0;
}
int main(){
    SqList L;
    initList_sq(&L);
    listPush_sq(&L,25);
    listPush_sq(&L,30);
    listPush_sq(&L,1);
    listPush_sq(&L,2);
    listInsert_sq(&L,2,50);
    printList_sq(&L);
    listDelete_sq(&L,1);
    printList_sq(&L);
    printf("%d\n", getElem_sq(&L,5));



    return 0;
}
