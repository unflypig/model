/*================================================================
*   Copyright (C) 2020 Sangfor Ltd. All rights reserved.
*   
*   文件名称：list.h
*   创 建 者：zt
*   创建日期：2020年01月31日
*   描    述：
*
================================================================*/
#ifndef __LIST_H__
#define __LIST_H__
typedef struct student{
    char name[64];
    unsigned int num;
}STU;
typedef struct node{
    STU student;
    struct node *next; 
}STU_LIST;
int InitList(STU_LIST **List);
int EmptyList(STU_LIST **List);
void DisplyItemData(const STU *student);
int ExecforEveryIterm(STU_LIST *List, void(*pfun)(const STU *student));
int CopyItemtoSTU(const char *name, const unsigned int num, STU *student);
int AddItemtoList(STU *student, STU_LIST **List);
/*Get Items of STU from lines read from database format likes name:num*/
int ShowListData(STU_LIST *List);
int LoadDatafromDatabase();
#endif
