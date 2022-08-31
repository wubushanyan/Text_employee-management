#ifndef FUNCTION_H
#define FUNCTION_H
#include "datebase.h"
#include "filecontrol.h"

//添加员工信息
void Add_staff(List *plist);
//删除员工信息
void Del_staff(List *plist);
//修改员工信息
void rev_staff(List *plist);


//基于工号查找
PNode find_num(List *plist,int mode); //mode=1，2 防key值重复检验(添加、修改)
//基于年龄查找
void find_age(List *plist);
//基于年龄查找rule,容错率低 废弃
void find_agerule(List *plist);


//基于工号排序
void sort_num(List *plist,int mode);
//基于年龄排序
void sort_age(List *plist,int mode);

//展示所有员工信息
void show_all(List *plist);
//清空所有员工信息
void clear_all(List *plist);

//等待函数
void wait();
#endif