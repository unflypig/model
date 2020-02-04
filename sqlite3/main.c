/*================================================================
*   Copyright (C) 2020 Sangfor Ltd. All rights reserved.
*   
*   文件名称：main.c
*   创 建 者：zt
*   创建日期：2020年02月03日
*   描    述：
*
================================================================*/

#include <stdio.h>
#include "sqlite3.h"
#define DB_PATH "./student.db"
#define STUDENT_TABLE_NAME "StudentData"
#define SUCCESS 0
#define FAIL -1
#define MAX_SQL_CMD_LEN 512;
int nrow, ncol;
sqlite3 *db= NULL; 
char *ErrorMsg = NULL;
char **Result = NULL;
//char sql_cmd[MAX_SQL_CMD_LEN] = {'\0'};
char *sql_cmd = NULL;
void PrintMsg(char **ErrorMsg){
    if(*ErrorMsg == NULL) {
        printf("SQL command executed with no error!\n");
        return ;
    }//endif
    if(*ErrorMsg) {
        printf("ERROR:%s\n", *ErrorMsg);
        *ErrorMsg = NULL;
    }//endif
}
int InitStudentsDatabase(sqlite3 *db){
    char *ErrorMsg;
    char *sql_cmd = "CREATE TABLE StudentData(\
                     ID INTEGER PRIMARY KEY,\
                     StudentNum INTEGER UNIQUE, \
                     StudentName VARCHAR(64),\
                     StudentAddress VARCHAR(128),\
                     StudentPhone VARCHAR(11)\
                     );";
    sqlite3_exec(db, sql_cmd, NULL, NULL, &ErrorMsg);
    PrintMsg(&ErrorMsg);
}
int ShowDBData(sqlite3 *db){
    sql_cmd = "SELECT * FROM StudentData";
    sqlite3_get_table(db, sql_cmd, &Result, &nrow, &ncol, &ErrorMsg);
    if(nrow > 1) {
        printf("row:%d, col:%d", nrow, ncol);
        int i, j;
        for(i = 0;i < (nrow+1) * ncol; ++i){
            if(i%5 == 0) {
                printf("\n");
            }//endif
            printf("%-20s", Result[i]);
        }//endfor
        printf("\n");
    }//endif
}
int main(int argc, char* argv[]){
#if 1
    sqlite3_open(DB_PATH, &db);
    InitStudentsDatabase(db);
    //Init table
    //insert data
    char *sql_cmd1 = "INSERT OR IGNORE INTO StudentData(ID, StudentNum, StudentName, StudentAddress, StudentPhone) \
                      VALUES(NULL, 1071120, '张涛', '安徽宣城', '18688755344');";
    sqlite3_exec(db, sql_cmd1, NULL, NULL, &ErrorMsg);
    PrintMsg(&ErrorMsg);
    char *sql_cmd2 = "INSERT OR IGNORE INTO StudentData(ID, StudentNum, StudentName, StudentAddress, StudentPhone) \
                      VALUES(NULL, 1071122, '刘鹏', '安徽海南', '18688755345');";
    sqlite3_exec(db, sql_cmd2, NULL, NULL, &ErrorMsg);
    PrintMsg(&ErrorMsg);
    char *sql_cmd3 = "INSERT OR IGNORE INTO StudentData(ID, StudentNum, StudentName, StudentAddress, StudentPhone)  \
                      VALUES(NULL, 1071124, '穆世欢', '安徽滁州', '18688755346');";
    sqlite3_exec(db, sql_cmd3, NULL, NULL, &ErrorMsg);
    PrintMsg(&ErrorMsg);
    //Select TABLE
    ShowDBData(db);
    //sprintf(sql_cmd,"SELECT * FROM %s", STUDENT_TABLE_NAME);
    sql_cmd = "SELECT * FROM StudentData where StudentNum==1071120";
    sqlite3_get_table(db, sql_cmd, &Result, &nrow, &ncol, &ErrorMsg);
    if(nrow >= 1) {
        printf("row:%d, col:%d", nrow, ncol);
        int i, j;
        for(i = 0;i < (nrow+1) * ncol; ++i){
            if(i%5 == 0) {
                printf("\n");
            }//endif
            printf("%-20s", Result[i]);
        }//endfor
        printf("\n");
    }//endif
    //delete data
    sql_cmd = "DELETE FROM StudentData WHERE StudentNum == 1071120";
    sqlite3_exec(db, sql_cmd, NULL, NULL, NULL);
    ShowDBData(db);
    sqlite3_close(db);
    
#endif
    return 0;
}
