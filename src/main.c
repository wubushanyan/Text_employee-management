#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/function.h"

int renewmeun(List *plist)
{
	int num = 0;
	getchar(); //吃回车
	while (1)
	{
		system("clear");
		printf("\n");
		printf("---------- 更新员工信息子菜单 -----------\n");
		printf("-           1.增加员工信息              -\n");
		printf("-           2.删除员工信息              -\n");
		printf("-           3.修改员工信息              -\n");
		printf("-           0.退出                      -\n");
		printf("-----------------------------------------\n");

		printf("请选择想要的操作序号：");
		scanf("%d", &num);
		if (num == 0)
		{
			system("clear");
			break;
		}
		switch (num)
		{
		case 1:
			Add_staff(plist);
			wait();
			break;
		case 2:
			Del_staff(plist);
			break;
		case 3:
			rev_staff(plist);
			break;
		default:
			printf("\n*********错误，请输入正确的数字！********\n\n");
		}
	}
	return 0;
}

int searchmeun(List *plist)
{
	int num = 0;
	getchar(); //吃回车
	while (1)
	{
		system("clear");
		printf("\n");
		printf("---------- 查找员工信息子菜单 -----------\n");
		printf("-           1.基于工号查找              -\n");
		printf("-           2.基于年龄查找              -\n");
		printf("-           0.退出                      -\n");
		printf("-----------------------------------------\n");

		printf("请选择想要的操作序号：");
		scanf("%d", &num);
		if (num == 0)
		{
			system("clear");
			break;
		}
		switch (num)
		{
		case 1:
			find_num(plist,0);
			wait();
			break;
		case 2:
			find_age(plist);
			wait();
			break;
		default:
			printf("\n*********错误，请输入正确的数字！********\n\n");
		}
	}
	return 0;
}

int sortmeun(List *plist)
{
	int num = 0;
	getchar(); //吃回车
	while (1)
	{
		printf("\n");
		printf("---------- 排序员工信息子菜单 -----------\n");
		printf("-           1.基于工号排序              -\n");
		printf("-           2.基于年龄排序              -\n");
		printf("-           0.退出                      -\n");
		printf("-----------------------------------------\n");

		printf("请选择想要的操作序号：");
		scanf("%d", &num);
		if (num == 0)
		{
			system("clear");
			break;
		}
		switch (num)
		{
		case 1:
			while (1)
			{
				getchar(); //吃回车
				system("clear");
				printf("\n");
				printf("---------- 基于工号排序子菜单 -----------\n");
				printf("-           1.升序                     -\n");
				printf("-           2.降序                     -\n");
				printf("-           0.退出                      -\n");
				printf("-----------------------------------------\n");

				printf("请选择想要的操作序号：");
				scanf("%d", &num);
				if (num == 0)
				{
					system("clear");
					break;
				}
				switch (num)
				{
				case 1:
					sort_num(plist,1);
					wait();
					break;
				case 2:
					sort_num(plist,2);
					wait();
					break;
				default:
					printf("\n*********错误，请输入正确的数字！********\n\n");
					break;
				}
			}
			break;
		case 2:
			while (1)
			{
				getchar(); //吃回车
				system("clear");
				printf("\n");
				printf("---------- 基于年龄排序子菜单 -----------\n");
				printf("-           1.升序                     -\n");
				printf("-           2.降序                     -\n");
				printf("-           0.退出                      -\n");
				printf("-----------------------------------------\n");

				printf("请选择想要的操作序号：");
				scanf("%d", &num);
				if (num == 0)
				{
					system("clear");
					break;
				}
				switch (num)
				{
				case 1:
					sort_age(plist,1);
					wait();
					break;
				case 2:
					sort_age(plist,2);
					wait();
					break;
				default:
					printf("\n*********错误，请输入正确的数字！********\n\n");
					break;
				}
			}
			break;
		default:
			printf("\n*********错误，请输入正确的数字！********\n\n");
		}
	}
	return 0;
}

int main()
{
	List *plist=Listinit();
	system("clear");
	int num = 0;
	char yon[5]={0};
	while (1)
	{
		printf("\n");
		printf("--------------- 主菜单 ------------------\n");
		printf("-           1.更新员工信息              -\n");
		printf("-           2.查找员工信息              -\n");
		printf("-           3.排序员工信息              -\n");
		printf("-           4.显示所有员工信息          -\n");
		printf("-           5.清空所有员工信息          -\n");
		printf("-           0.退出                      -\n");
		printf("-----------------------------------------\n");
		printf("请选择想要的操作序号：");
		scanf("%d", &num);
		if (num == 0)
		{
			system("clear");
			printf("\n\n再见~\n");
			break;
		}
		switch (num)
		{
		case 1:
			system("clear");
			renewmeun(plist);
			break;
		case 2:
			system("clear");
			searchmeun(plist);
			break;
		case 3:
			system("clear");
			sortmeun(plist);
			break;
		case 4:
			system("clear");
			show_all(plist);
			wait();
			system("clear");
			break;
		case 5:
			system("clear");
			while (1)
			{
				getchar(); //吃回车
				printf("是否清空所有员工信息y/n):");
				scanf("%s", yon);
				system("clear");
				if (strcmp(yon,"Y")==0 || strcmp(yon,"y")==0)
				{
					system("clear");
					printf("\n正在清空所有员工信息!!!\n");
					clear_all(plist);
					wait();
					system("clear");
					break;
				}
				if (strcmp(yon,"N")==0 || strcmp(yon,"n")==0)
				{
					system("clear");
					break;
				}
				printf("\n*********错误，请输入正确的字母！********\n\n");
			}
			break;
		default:
			system("clear");
			printf("\n*********错误，请输入正确的数字！********\n\n");
		}
	}

	return 0;
}
