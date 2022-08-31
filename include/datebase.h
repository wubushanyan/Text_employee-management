#ifndef DATEBASH_H
#define DATEBASH_H
// Pnode 结构体指针 Node结构体 List 链表

//变量改名：  Node*->PNode
typedef struct Node* PNode;

//结构体定义
typedef struct Node
{
    char num[10];
    char enname[10];
    char age[5];
    char sex[5];
    PNode pre;
    PNode next;
} Node;

typedef struct Node* PNode;

//链表定义  服务于size
typedef struct
{
    int size; //记录节点数量
    PNode head;
    PNode tail;
} List;

//节点创建
PNode Nodeinit();
//链表创建
List *Listinit();
//链表元素添加
void Nodeadd(List *plist, PNode p);
//链表元素删除
void Nodedel(List *plist, PNode p);
//链表清空
void Listdestroy(List *plist);
//获取尾节点
PNode Gettail(List *plist);
//获取头结点
PNode Gethead(List *plist);
//获取链表长度
int Getsize(List *plist);
//判空
int Isempty(List *plist);
#endif