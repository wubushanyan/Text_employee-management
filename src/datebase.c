#include <stdio.h>
#include <stdlib.h>
#include "../include/datebase.h"

//节点创建
PNode Nodeinit()
{
    PNode p = NULL;
    p = (PNode)malloc(sizeof(Node));
    p->pre = NULL;
    p->next = NULL;
    return p;
}
//双向链表初始化
List *Listinit()
{
    List *PList = (List *)malloc(sizeof(List));
    PNode head = Nodeinit(); //头结点创建 不存数据
    PList->head = head;
    PList->tail = head;
    PList->size = 0;
    return PList;
}

//添加节点
void Nodeadd(List *plist, PNode p)
{
    //头插法
    if (0 == plist->size) //空链表
    {
        plist->head->next = p;
    }
    else
    {
        plist->tail->next = p; //前节点的后指针指向待添加节点
        p->pre = plist->tail;  //待添加节点前指针指向链表尾部
    }
    plist->tail = p; //移动链表尾指针指向待添加节点
    plist->size++;
}

//删除节点
void Nodedel(List *plist, PNode p)
{
    //如果是头结点
    if (p == plist->head->next)
    {
        plist->head->next = p->next;
    }
    //如果是尾节点
    else if (p == plist->tail)
    {
        plist->tail = p->pre;
        p->pre->next=NULL;
    }
    //中间节点
    else
    {
        p->pre->next = p->next;
        p->next->pre = p->pre;
    }

    plist->size--; 
    free(p);
}
void Listdestroy(List *plist)
{
    if(plist->head==NULL)
    return;
    PNode p,q;
    p=plist->head->next;
    while(p!=NULL)
    {
        q=p->next;
        free(p);
        p=q;
    }
    plist->size=0;
    // free(q);
    // free(plist->head->next);
    return;
}

PNode Gettail(List *plist)
{
    return plist->tail;
}

PNode Gethead(List *plist)
{
    return plist->head;
}

int Getsize(List *plist)
{
    return plist->size;
}

int Isempty(List *plist)
{
    if(Getsize(plist) == 0 && Gettail(plist) == Gethead(plist))
    {
        //空
		return 1;
    }
	else
    {
        //非空
		return 0;
    }
}






/* void main()
{
    List* plist=Listinit();
    PNode p=Nodeinit();
    free(p);
    printf("编译 test\n");
} */