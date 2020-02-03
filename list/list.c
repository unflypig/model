/*================================================================
*   Copyright (C) 2020 Sangfor Ltd. All rights reserved.
*   
*   文件名称：link-list-all.c
*   创 建 者：zt
*   创建日期：2020年01月30日
*   描    述：
*
================================================================*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"
#define LINE_MAX_BYTE 128
#define SUCCESS 0
#define FAIL -1
#define DATA_BASE_PATH "./students"
int InitList(STU_LIST **List){
    *List = NULL;
    return SUCCESS;
}
int EmptyList(STU_LIST **List){
    STU_LIST *current , *prev;
    current = *List;
    while(current){
        prev = current;
        free(current);
        current = NULL;
        current = prev->next;
    }//endwhile
    printf("Empty list success!\n");
    return SUCCESS;
}
int CopyItemtoSTU(const char *name, const unsigned int num, STU *student){
    if(name != NULL && num > 0 && student != NULL) {
        strncpy(student->name, name, strlen(name));
        student->num = num;
    }else{
        printf("input argument error!\n");
        return FAIL;
    }//endif
    return SUCCESS;
}
static STU_LIST * CreatNewNode(STU *student){
   STU_LIST *new_node = (STU_LIST *)malloc(sizeof(STU_LIST));
   if(new_node) {
       new_node->student = *student;
       new_node->next = NULL;
   }//endif
   return new_node;
}
int AddItemtoList(STU *student, STU_LIST **List){
    STU_LIST *prev, *current;
    STU_LIST *pnew = CreatNewNode(student);
    if(pnew) {
        current = *List;
        if(*List == NULL) {//List is empty
            printf("List is empty, initial it!!\n");
            *List = pnew;
        }else{
            printf("List is not empty!\n");
            while(current->next != NULL){
                printf("This is not the end of list, continue...\n");
                current = current->next;
            }//endwhile
            current->next = pnew;
            printf("Add Item to list success!\n");
        }//endif
        return SUCCESS;
    }else{
        printf("malloc fail!\n");
        return FAIL;
    }//endif
}
/*Get Items of STU from lines read from database format likes name:num*/
static int GetItemfromLine(char *line, STU *student){
    char name[64] = {'\0'};
    char num[8] = {'\0'};
    char *tmp;
    if(tmp = strchr(line, ':')){
        *tmp = '\0';
        strncpy(name, line, strlen(line));
    }//endif
    ++tmp;
    strncpy(num, tmp, strlen(tmp)-1);
    strncpy(student->name, name, strlen(name));
    student->num = atoi(num);
    //printf("name[%s]\n", student->name);
    //printf("num[%d]\n", student->num);
    return SUCCESS;
}
int ShowListData(STU_LIST *List){
    STU_LIST *current = List;
    while(current){
        printf("%s的学号是:%d\n", current->student.name, current->student.num);
        current = current->next;
    }//endwhile
    return SUCCESS;
}
void DisplyItemData(const STU *student){
    if(student) {
        printf("%s的学号是:%d\n", student->name, student->num);
    }
}
int ExecforEveryIterm(STU_LIST *List, void(*pfun)(const STU *student)){
    STU_LIST *current = List;
    while(current){
        pfun(&(current->student));
        current = current->next;
    }//endwhile 
}
int LoadDatafromDatabase(STU_LIST **List){
    char line[LINE_MAX_BYTE] = {'\0'};
    FILE *data_base_fp = fopen(DATA_BASE_PATH, "r");
    if(data_base_fp) {
        //printf("1\n");
       while(fgets(line, LINE_MAX_BYTE, data_base_fp)) {
           STU student;
           printf("line is [%s]\n", line);
           GetItemfromLine(line, &student);
           AddItemtoList(&student, List);
          // ShowListData(List);
       }//endif 
    }else{
        printf("open data base file fail!\n");
        return FAIL;
    }//endif
    return SUCCESS;
}
