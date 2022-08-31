#ifndef FILECONTROL_H
#define FILECONTROL_H

#include "datebase.h"
#define FILE_LOC "./datebase.txt"

//刷写文件
void WriteFile(List *plist);

//读取文件
void ReadFile(List *plist);

#endif