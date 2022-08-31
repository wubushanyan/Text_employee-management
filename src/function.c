#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/function.h"

//////////////////////////////////////////////////////////////////////////////////////////////////添加员工信息
void Add_staff(List *plist)
{
    char yon[5]={0};

    FILE *fp = fopen(FILE_LOC, "r");
    if (fp == NULL)
    {
        //刷新内存链表
        FILE *fp = fopen(FILE_LOC, "w+");
    }
    ReadFile(plist);
    // wait();
    system("clear");
    PNode o = find_num(plist, 1);
    if (o != NULL)
    {
        printf("此工号已存在，请修改或删除后重新添加\n");
        return;
    }
    while (1)
    {
        PNode p = Nodeinit();
        printf("ps:输入 0 即可返回上层菜单\n");
        printf("请输入员工工号:");
        scanf("%s", p->num);
        if (!strcmp(p->num, "0"))
            break;
        printf("请输入员工英文姓名:");
        scanf("%s", p->enname);
        if (!strcmp(p->enname, "0"))
            break;
        printf("请输入员工年龄:");
        scanf("%s", p->age);
        if (!strcmp(p->age, "0"))
            break;
        printf("请输入员工性别(男、女、未知):");
        scanf("%s", p->sex);
        if (!strcmp(p->sex, "0"))
            break;
        system("clear");
        printf("本次添加员工信息如下：\n%s\t%s\t%s\t%s\t\n", p->num, p->enname, p->age, p->sex);

        getchar(); //吃回车
        printf("请确认是否添加y/n:");
        scanf("%s", yon);
        system("clear");
        if (strcmp(yon,"Y")==0 || strcmp(yon,"y")==0)
        {
            Nodeadd(plist, p);
            //刷写文本文件
            WriteFile(plist);
            printf("添加成功\n");
            break;
        }
        if (strcmp(yon,"N")==0 || strcmp(yon,"n")==0)
        {
            printf("取消添加");
            break;
        }
        printf("\n*********错误，请输入正确的字母！********\n\n");
    }
    return;
}

//////////////////////////////////////////////////////////////////////////////////////////////////删除员工信息
void Del_staff(List *plist)
{
    //刷新内存链表
    ReadFile(plist);
    system("clear");

    char yon[5] = {0};
    //检查是否含有待删除数据
    PNode p = find_num(plist, 0);
    if (p == NULL)
        return;
    else
    {
        while (1)
        {
            getchar(); //吃回车
                       // printf("待删除员工信息：\n%s\t%s\t%s\t%s\t\n",p->num,p->enname,p->age,p->sex);
            printf("\n是否删除该员工数据y/n:");
            scanf("%s", yon);
            system("clear");
            if (strcmp(yon,"Y")==0 || strcmp(yon,"y")==0)
            {
                system("clear");
                Nodedel(plist, p);
                printf("\n已清除该员工信息\n");
                break;
            }
            if (strcmp(yon,"N")==0 || strcmp(yon,"n")==0)
            {
                system("clear");
                break;
            }
            printf("\n*********错误，请输入正确的字母！********\n\n");
        }
    }
    //刷写文本文件
    WriteFile(plist);
    return;
}

//////////////////////////////////////////////////////////////////////////////////////////////////修改员工信息
void rev_staff(List *plist)
{
    //刷新内存链表
    ReadFile(plist);
    system("clear");

    char yon = 'n';
    //检查是否含有待修改数据
    PNode p = find_num(plist, 0);
    if (p == NULL)
        return;
    else
    {
        while (1)
        {
            getchar(); //吃回车
            PNode q = Nodeinit();
            printf("\nps:输入 0 即可退出修改\n");
            printf("请输入员工工号修改值:");
            scanf("%s", q->num);
            if (!strcmp(q->num, "0"))
                break;
            printf("请输入员工英文姓名修改值:");
            scanf("%s", q->enname);
            if (!strcmp(q->enname, "0"))
                break;
            printf("请输入员工年龄修改值:");
            scanf("%s", q->age);
            if (!strcmp(q->age, "0"))
                break;
            printf("请输入员工性别修改值(男、女、未知):");
            scanf("%s", q->sex);
            if (!strcmp(q->sex, "0"))
                break;
            system("clear");
            printf("员工修改前信息：\n%s\t%s\t%s\t%s\t\n", p->num, p->enname, p->age, p->sex);
            printf("\n员工修改后信息：\n%s\t%s\t%s\t%s\t\n", q->num, q->enname, q->age, q->sex);
            printf("\n是否修改该员工数据y/n:");
            getchar(); //吃回车
            scanf("%c", &yon);
            system("clear");
            if (yon == 'Y' || yon == 'y')
            {
                system("clear");
                strcpy(p->num, q->num);
                strcpy(p->enname, q->enname);
                strcpy(p->age, q->age);
                strcpy(p->sex, q->sex);
                printf("\n已修改该员工信息\n");
                break;
            }
            if (yon == 'N' || yon == 'n')
            {
                system("clear");
                break;
            }
            printf("\n*********错误，请输入正确的字母！********\n\n");
            free(q);
        }
    }
    //刷写文本文件
    WriteFile(plist);
    return;
}

//////////////////////////////////////////////////////////////////////////////////////////////////基于工号查找
PNode find_num(List *plist, int mode)
{
    //刷新内存链表
    ReadFile(plist);
    system("clear");
    if (mode == 1)
    {
        printf("为防添加导致工号重复，请输入待添加工号进行检验\n");
    }
    if (mode == 2)
    {
        printf("为防修改导致工号重复，请输入待修改工号进行检验\n");
    }
    int size = Getsize(plist);
    char num[20] = {0};
    PNode p = plist->head->next;
    // getchar(); //吃回车
    printf("请输入员工工号：");
    scanf("%s", num);
    while (size--)
    {
        //基于工号寻找
        if (p == plist->tail && strcmp(num, p->num) != 0)
        {
            system("clear");
            if (mode == 1)
            {
                printf("系统内无此工号，可添加\n");
            }
            else if (mode == 2)
            {
                printf("系统内无此工号，可修改\n");
            }
            else
            {
                printf("查无此人！\n");
            }
            return NULL;
        }
        if (strcmp(num, p->num) == 0)
        {
            system("clear");
            printf("该员工信息如下：\n%s\t%s\t%s\t%s\t\n", p->num, p->enname, p->age, p->sex);
            return p;
        }
        else
            p = p->next;
    }
}
/* ////////////////////////////////////////////////////////////////////////////////////////////////基于年龄查找rule
void find_agerule(List *plist)
{
    //刷新内存链表
    ReadFile(plist);
    system("clear");
    int size = Getsize(plist);
    char age[20] = {0};
    char rule[20] = {0};
    PNode p = plist->head->next;
    printf("例子：<18  <=18  >18  >=18  ==18  !=18  >18<20(大于18小于20)\n");
    printf("请输入基于年龄的查找规则：");
    scanf("%s",rule);
    printf("查找信息如下：\n");
    while(size--)
    {
        if(strstr(rule,"<")&& !strstr(rule, "=")&& !strstr(rule, ">"))  //小于
        {
            // printf("%s",strtok(rule,"<"));
            if(atoi(p->age) <atoi(strtok(rule,"<")))
            printf("%s\t%s\t%s\t%s\t\n",p->num, p->enname, p->age, p->sex);
        }
        else if (strstr(rule,"<=")) //小于等于
        {
            if(atoi(p->age) <= atoi(strtok(rule,"<=")))
            printf("%s\t%s\t%s\t%s\t\n",p->num, p->enname, p->age, p->sex);
        }
        else if (strstr(rule,">")&& !strstr(rule, "=")&& !strstr(rule, "<"))//大于
        {
            if(atoi(p->age) > atoi(strtok(rule,">")))
            printf("%s\t%s\t%s\t%s\t\n",p->num, p->enname, p->age, p->sex);
        }
        else if (strstr(rule,">="))//大于等于
        {
            if(atoi(p->age) >= atoi(strtok(rule,">=")))
            printf("%s\t%s\t%s\t%s\t\n",p->num, p->enname, p->age, p->sex);
        }
        else if (strstr(rule,"=="))//等于
        {
            if(atoi(p->age) == atoi(strtok(rule,"==")))
            printf("%s\t%s\t%s\t%s\t\n",p->num, p->enname, p->age, p->sex);
        }
        else if (strstr(rule,"!="))//不等于
        {
            if(atoi(p->age) != atoi(strtok(rule,"!=")))
            printf("%s\t%s\t%s\t%s\t\n",p->num, p->enname, p->age, p->sex);
        }
        else if (strstr(rule,">")&&strstr(rule,"<"))//大于 且 小于
        {
            printf("%d\n",atoi(strtok(rule,">")));
            printf("%d\n",atoi(strtok(strtok(NULL,">"),"<")));
            // if(atoi(p->age) > atoi(strtok(rule,">")) && atoi(p->age) < atoi(strtok(strtok(rule,">"),"<")))
            // printf("%s\t%s\t%s\t%s\t\n",p->num, p->enname, p->age, p->sex);
        }
        p=p->next;
    }
    while(1)
    {
        char num[5]={0};
        getchar(); //吃回车
        printf("\n输入 0 返回:");
        scanf("%s",num);
        if(!strcmp(num,"0"))break;
    }
    return;
} */

//////////////////////////////////////////////////////////////////////////////////////////////////基于年龄查找
void find_age(List *plist)
{
    int num, flag = 0;
    int no1 = 0, no2 = 0;
    char no[5];
    //刷新内存链表
    ReadFile(plist);
    PNode p = plist->head->next;
    while (1)
    {
        system("clear");
        printf("1.小于  2.小于等于  3.大于  4.大于等于  5.等于  6.不等于  7.区间(开区间)\n");
        printf("请输入查找规则编号：");
        scanf("%d", &num);
        fflush(stdin); //刷新缓冲区
        if (num == 7)
        {
            printf("请输入区间左值(整数且>=0):");
            scanf("%d", &no1);
            printf("请输入区间右值(整数且>=0且>左值):");
            scanf("%d", &no2);
            // printf("%d %d",no1,no2);//test
            break;
        }
        else if (num < 7 && num > 0)
        {
            printf("请输入界限值(整数且>=0):");
            scanf("%d", &no1);
            break;
        }
        else
        {
            printf("\n*********错误，请输入正确的数字！********\n\n");
            return;
        }
    }
    printf("查找信息如下：\n");
    int size = Getsize(plist);
    int szie = plist->size;
    while (size--)
    {
        switch (num)
        {
        case 1:
            // printf("1  %d\n",no1);//test
            if (atoi(p->age) < no1)
            {
                printf("%s\t%s\t%s\t%s\t\n", p->num, p->enname, p->age, p->sex);
                flag = 1;
            }
            break;
        case 2:
            // printf("2\n");//test
            if (atoi(p->age) <= no1)
            {
                printf("%s\t%s\t%s\t%s\t\n", p->num, p->enname, p->age, p->sex);
                flag = 1;
            }
            break;
        case 3:
            // printf("3 %d %d\n",atoi(p->age),no1);//test
            if (atoi(p->age) > no1)
            {
                printf("%s\t%s\t%s\t%s\t\n", p->num, p->enname, p->age, p->sex);
                flag = 1;
            }
            break;
        case 4:
            // printf("4 %d %d\n",atoi(p->age),no1);//test
            if (atoi(p->age) >= no1)
            {
                printf("%s\t%s\t%s\t%s\t\n", p->num, p->enname, p->age, p->sex);
                flag = 1;
            }
            break;
        case 5:
            // printf("5\n");//test
            if (atoi(p->age) == no1)
            {
                printf("%s\t%s\t%s\t%s\t\n", p->num, p->enname, p->age, p->sex);
                flag = 1;
            }
            break;
        case 6:
            // printf("6\n");//test
            if (atoi(p->age) != no1)
            {
                printf("%s\t%s\t%s\t%s\t\n", p->num, p->enname, p->age, p->sex);
                flag = 1;
            }
            break;
        case 7:
            // printf("7\n");//test
            if (atoi(p->age) > no1 && atoi(p->age) < no2)
            {
                printf("%s\t%s\t%s\t%s\t\n", p->num, p->enname, p->age, p->sex);
                flag = 1;
            }
            break;
        default:
            break;
        }
        p = p->next;
    }
    if(flag==0)
    {
        printf("\n无符合员工！\n");
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////基于工号排序
void sort_num(List *plist, int mode) // mode=1 升序 mode=2 降序
{
    //刷新内存链表
    ReadFile(plist);
    int i, j;
    int size = Getsize(plist);
    //初始指针
    PNode p = plist->head;
    PNode pn = plist->head;
    for (i = 1; i < size; i++)
    {
        //重置指针
        p = plist->head->next; //指向第一个数据节点
        pn = p->next;
        for (j = 1; j <= size - i; j++)
        {
            // printf("p:%d pn=%d", atoi(p->num), atoi(pn->num)); // test
            if (mode == 1)
            {
                if (atoi(p->num) > atoi(pn->num))
                {
                    //涉及头结点
                    if (p->pre == NULL)
                    {
                        // printf("头结点交换\n"); // test
                        plist->head->next = pn; //修正头指针

                        //交换五步骤
                        pn->pre = p->pre;   //覆盖（待交换）前指针
                        pn->next->pre = p;  //覆盖（待交换下一跳）前指针
                        p->next = pn->next; //覆盖（当前）后指针
                        p->pre = pn;        //覆盖(当前)前指针
                        pn->next = p;       //覆盖(待交换)后指针
                        pn = p->next;
                        continue;
                    }
                    //涉及尾节点
                    if (pn->next == NULL)
                    {
                        // printf("尾节点交换\n"); // test
                        //交换五步骤
                        p->next = pn->next; //覆盖(当前)后指针
                        pn->pre = p->pre;   //覆盖（待交换）前指针
                        pn->next = p;       //覆盖(待交换)后指针
                        p->pre->next = pn;  //覆盖（当前上一跳）后指针
                        p->pre = pn;        //覆盖(当前)前指针
                        break;
                    }
                    //交换六步骤
                    // printf("中间点交换\n");
                    p->pre->next = pn;  //覆盖（当前上一跳）后指针
                    pn->pre = p->pre;   //覆盖（待交换）前指针
                    pn->next->pre = p;  //覆盖（待交换下一跳）前指针
                    p->next = pn->next; //覆盖（当前）后指针
                    p->pre = pn;        //覆盖(当前)前指针
                    pn->next = p;       //覆盖(待交换)后指针

                    pn = p->next; //指针后移
                }
                else
                {
                    // printf("不交换\n"); // test
                    p = p->next; //指针后移
                    pn = pn->next;
                }
            }
            else if (mode == 2)
            {
                if (atoi(p->num) < atoi(pn->num))
                {
                    //涉及头结点
                    if (p->pre == NULL)
                    {
                        // printf("头结点交换\n"); // test
                        plist->head->next = pn; //修正头指针

                        //交换五步骤
                        pn->pre = p->pre;   //覆盖（待交换）前指针
                        pn->next->pre = p;  //覆盖（待交换下一跳）前指针
                        p->next = pn->next; //覆盖（当前）后指针
                        p->pre = pn;        //覆盖(当前)前指针
                        pn->next = p;       //覆盖(待交换)后指针
                        pn = p->next;
                        continue;
                    }
                    //涉及尾节点
                    if (pn->next == NULL)
                    {
                        // printf("尾节点交换\n"); // test
                        //交换五步骤
                        p->next = pn->next; //覆盖(当前)后指针
                        pn->pre = p->pre;   //覆盖（待交换）前指针
                        pn->next = p;       //覆盖(待交换)后指针
                        p->pre->next = pn;  //覆盖（当前上一跳）后指针
                        p->pre = pn;        //覆盖(当前)前指针
                        break;
                    }
                    //交换六步骤
                    // printf("中间点交换\n");
                    p->pre->next = pn;  //覆盖（当前上一跳）后指针
                    pn->pre = p->pre;   //覆盖（待交换）前指针
                    pn->next->pre = p;  //覆盖（待交换下一跳）前指针
                    p->next = pn->next; //覆盖（当前）后指针
                    p->pre = pn;        //覆盖(当前)前指针
                    pn->next = p;       //覆盖(待交换)后指针

                    pn = p->next; //指针后移
                }
                else
                {
                    // printf("不交换\n"); // test
                    p = p->next; //指针后移
                    pn = pn->next;
                }
            }
        }
        WriteFile(plist);
    }
    printf("排序完成！\n");
    show_all(plist);
}

//////////////////////////////////////////////////////////////////////////////////////////////////基于年龄排序
void sort_age(List *plist, int mode)
{
    //刷新内存链表
    ReadFile(plist);
    int i, j;
    int size = Getsize(plist);
    //初始指针
    PNode p = plist->head;
    PNode pn = plist->head;
    for (i = 1; i < size; i++)
    {
        //重置指针
        p = plist->head->next; //指向第一个数据节点
        pn = p->next;
        for (j = 1; j <= size - i; j++)
        {
            // printf("p:%d pn=%d", atoi(p->num), atoi(pn->num)); // test
            if (mode == 1)
            {
                if (atoi(p->age) > atoi(pn->age))
                {
                    //涉及头结点
                    if (p->pre == NULL)
                    {
                        // printf("头结点交换\n"); // test
                        plist->head->next = pn; //修正头指针

                        //交换五步骤
                        pn->pre = p->pre;   //覆盖（待交换）前指针
                        pn->next->pre = p;  //覆盖（待交换下一跳）前指针
                        p->next = pn->next; //覆盖（当前）后指针
                        p->pre = pn;        //覆盖(当前)前指针
                        pn->next = p;       //覆盖(待交换)后指针
                        pn = p->next;
                        continue;
                    }
                    //涉及尾节点
                    if (pn->next == NULL)
                    {
                        // printf("尾节点交换\n"); // test
                        //交换五步骤
                        p->next = pn->next; //覆盖(当前)后指针
                        pn->pre = p->pre;   //覆盖（待交换）前指针
                        pn->next = p;       //覆盖(待交换)后指针
                        p->pre->next = pn;  //覆盖（当前上一跳）后指针
                        p->pre = pn;        //覆盖(当前)前指针
                        break;
                    }
                    //交换六步骤
                    // printf("中间点交换\n");
                    p->pre->next = pn;  //覆盖（当前上一跳）后指针
                    pn->pre = p->pre;   //覆盖（待交换）前指针
                    pn->next->pre = p;  //覆盖（待交换下一跳）前指针
                    p->next = pn->next; //覆盖（当前）后指针
                    p->pre = pn;        //覆盖(当前)前指针
                    pn->next = p;       //覆盖(待交换)后指针

                    pn = p->next; //指针后移
                }
                else
                {
                    // printf("不交换\n"); // test
                    p = p->next; //指针后移
                    pn = pn->next;
                }
            }
            else if (mode == 2)
            {
                if (atoi(p->age) < atoi(pn->age))
                {
                    //涉及头结点
                    if (p->pre == NULL)
                    {
                        // printf("头结点交换\n"); // test
                        plist->head->next = pn; //修正头指针

                        //交换五步骤
                        pn->pre = p->pre;   //覆盖（待交换）前指针
                        pn->next->pre = p;  //覆盖（待交换下一跳）前指针
                        p->next = pn->next; //覆盖（当前）后指针
                        p->pre = pn;        //覆盖(当前)前指针
                        pn->next = p;       //覆盖(待交换)后指针
                        pn = p->next;
                        continue;
                    }
                    //涉及尾节点
                    if (pn->next == NULL)
                    {
                        // printf("尾节点交换\n"); // test
                        //交换五步骤
                        p->next = pn->next; //覆盖(当前)后指针
                        pn->pre = p->pre;   //覆盖（待交换）前指针
                        pn->next = p;       //覆盖(待交换)后指针
                        p->pre->next = pn;  //覆盖（当前上一跳）后指针
                        p->pre = pn;        //覆盖(当前)前指针
                        break;
                    }
                    //交换六步骤
                    // printf("中间点交换\n");
                    p->pre->next = pn;  //覆盖（当前上一跳）后指针
                    pn->pre = p->pre;   //覆盖（待交换）前指针
                    pn->next->pre = p;  //覆盖（待交换下一跳）前指针
                    p->next = pn->next; //覆盖（当前）后指针
                    p->pre = pn;        //覆盖(当前)前指针
                    pn->next = p;       //覆盖(待交换)后指针

                    pn = p->next; //指针后移
                }
                else
                {
                    // printf("不交换\n"); // test
                    p = p->next; //指针后移
                    pn = pn->next;
                }
            }
        }
        WriteFile(plist);
    }
    printf("排序完成！");
    show_all(plist);
}

//////////////////////////////////////////////////////////////////////////////////////////////////展示所有员工信息
void show_all(List *plist)
{
    ReadFile(plist);
    int size = Getsize(plist);
    PNode p = plist->head->next;
    printf("所有员工信息：\n工号\t姓名\t年龄\t性别\t\n");
    while (size--)
    {
        printf("%s\t %s\t %s\t %s\t \n", p->num, p->enname, p->age, p->sex);
        p = p->next;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////清空所有员工信息
void clear_all(List *plist)
{
    Listdestroy(plist);
    WriteFile(plist);
    printf("员工信息已全部清空！\n");
}

void wait()
{
    char temp[5] = {0};
    while (1)
    {
        printf("\n输入 0 返回:");
        scanf("%s", temp);
        if (!strcmp(temp, "0"))
            break;
    }
    return;
}

/* void main()
{
    List *plist = Listinit();
    // Add_staff(plist);
    // find_num(plist);
    // Del_staff(plist);
    // rev_staff(plist);
    // find_age(plist);
    // find_agerule(plist);
    // sort_num(plist, 1);
    // show_all(plist);
    // sort_age(plist,2);
    show_all(plist);
    clear_all(plist);
    printf("编译 test:%d\n", plist->size);
} */