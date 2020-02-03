/*================================================================
*   Copyright (C) 2020 Sangfor Ltd. All rights reserved.
*   
*   文件名称：main.c
*   创 建 者：zt
*   创建日期：2020年01月31日
*   描    述：
*
================================================================*/

#include <stdio.h>
#include "list.h"
int main(int argc, char* argv[]){
    STU_LIST *List;
    InitList(&List);
    LoadDatafromDatabase(&List);
    //ShowListData(List);
    ExecforEveryIterm(List, DisplyItemData);
    EmptyList(&List);
    return 0;
}
