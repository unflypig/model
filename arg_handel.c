/*================================================================
*   Copyright (C) 2020 Sangfor Ltd. All rights reserved.
*   
*   文件名称：main.c
*   创 建 者：zt
*   创建日期：2020年01月08日
*   描    述：
*
================================================================*/


#include <stdio.h>
#include <getopt.h>
#include <string.h>
#define PROGRAM_VERSION "1.0"
#define OPTSTRING "in:a:s:A::e::?h:f:m:"
/*values*/
static s_inited = 0;
/*globals*/
#if 0
typedef struct {
    char name[64];
    int age;
    char sex[16];
    char father_name[64];
    char mother_name[64];
    char address[256];
    char email[64];
}STUDENT;
#else
typedef struct {
    int age;
    char* name;
    char* sex;
    char* father_name;
    char* mother_name;
    char* email;
    char address[64];
}STUDENT;
#endif

static const struct option  S_longOpt[] = {
    {"init", no_argument, &s_inited, 1},
    {"name", required_argument, NULL, 'n'},
    {"age", required_argument, NULL, 'a'},
    {"sex", required_argument, NULL, 's'},
    {"address", required_argument, NULL, 'A'},
    {"email", required_argument, NULL, 'e'},
    {"version", no_argument, NULL, 'V'},
    {NULL, 0, NULL, 0}
};
static void usage(void){
    fprintf(stderr, 
            "webbench [option]... URL\n"
            "   -i|--init           do init\n"
            "   -n|--name           name of student\n"
            "   -a|--age            age of student\n"
            "   -s|--sex            sex of student\n"
            "   -f|--father         father name of student\n"
            "   -m|--mother         mother name of student\n"
            "   -A|--address        address of student\n"
            "   -e|--email          email of student\n"
            "   -?|-h|--help        This information.\n"
            "   -V|--version        Display program version.\n"
            );
}
static void init(void){
    printf("init success\n");
}
int main(int argc, char* argv[]){
    int opt = 0;
    int options_index = 0;
    char *tmp = NULL;
    char stu_addr_province[32] = {'\0'};
    char stu_addr_city[32] = {'\0'};
    STUDENT S_student;
    memset(&S_student, 0, sizeof(STUDENT));
    if(argc == 1) {
        usage();
        return -1;
    }//endif
    while((opt = getopt_long(argc, argv, OPTSTRING, S_longOpt, &options_index)) != EOF){
        switch(opt)
        {
            case 'i'://init
                init();
                break;
            case 'n'://name
                S_student.name = optarg;
                break;
            case 's'://sex
                S_student.sex = optarg;
                break;
            case 'f'://father_name
                S_student.father_name = optarg;
                break;
            case 'm'://mother_name
                S_student.mother_name = optarg;
                break;
            case 'a'://age
                S_student.age = atoi(optarg);
                break;
            case 'e'://email
                S_student.email = optarg;
                break;
            case 'V'://program Version
                printf("Program Version:%s\n", PROGRAM_VERSION);
                return 0;
                break;
            case 'A'://address
                //S_student.address = optarg;
                //char address_tmp[64];
                //memcpy(address_tmp, optarg, strlen(optarg)-1);
                tmp = strchr(optarg, ':');
                if(tmp == NULL) {
                    break;
                }//endif
                if(tmp == optarg) {
                    fprintf(stderr,"Error in option --address \"%s\":Missing province.\n", optarg);
                    return -2;
                }//endif
                if(tmp == optarg+(strlen(optarg)-1)) {//若冒号后面没有其他字符
                   fprintf(stderr,"Error in option --address \"%s\":Missing city\n", optarg); 
                   return -3;
                }//endif
                //stu_addr_city = tmp + 1;
                /*get province*/
                *tmp = '\0';
                memcpy(stu_addr_province, optarg, strlen(optarg));
                /*get city*/
                ++tmp;
                memcpy(stu_addr_city, tmp, strlen(tmp));
                strncpy(S_student.address, strcat(stu_addr_province, "省"),32);
                strncpy(S_student.address, strcat(S_student.address, strcat(stu_addr_city, "市")), 32);
                break;
            case 'h':
            case '?':
                usage();
                return -4;
                break;
            default:break;
        }//endswitch

    }//endwhile
    printf("name:%s\n", S_student.name);
    printf("father name:%s\n", S_student.father_name);
    printf("mother name:%s\n", S_student.mother_name);
    printf("age:%d\n", S_student.age);
    if(S_student.address) {
        printf("address:%s\n", S_student.address);
    }//endif
    if(S_student.email) {
        printf("email:%s\n", S_student.email);
    }//endif
    return 0;
}
