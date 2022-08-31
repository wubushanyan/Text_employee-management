#include <stdio.h>
#include <stdlib.h>
#include "../include/filecontrol.h"

//刷写文件
void WriteFile(List *plist)
{
    FILE *fp = fopen(FILE_LOC, "w");
    if (fp != NULL)
    {
        int size = Getsize(plist);
        PNode p = plist->head->next;
        while (size--)
        {
            fprintf(fp, "%s\t%s\t%s\t%s\t\n", p->num, p->enname, p->age, p->sex);
            p = p->next;
        }
    }
    fclose(fp);
}

//刷写内存链表
void ReadFile(List *plist)
{
    Listdestroy(plist);
    FILE *fp = fopen(FILE_LOC, "r");
    if (fp == NULL)
    {
        printf("本地没有数据文件\n");
        printf("建议：1.请尝试添加员工信息生成文件\n");
        printf("      2.或者导入文件到程序顶级目录\n");
        exit(1);
    }
    plist->size=0;
    while (1)
    {
        PNode p = Nodeinit();
        //读到最后break
        if(feof(fp))break;
        fscanf(fp, "%s\t%s\t%s\t%s\t\n", p->num, p->enname, p->age, p->sex);
        //如果没有数据节点
        if (0 == Getsize(plist))
        {
            plist->head->next = p;
        }
        else
        {
            plist->tail->next = p;
            p->pre = plist->tail;
        }
        plist->tail = p;
        plist->size++;
    }
    fclose(fp);
}

/* void main()
{
    List *plist = Listinit();
    WriteFile(plist);
    ReadFile(plist);
    printf("编译 test\n");
} */