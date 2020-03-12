/*================================================================
*   Copyright (C) 2020 Sangfor Ltd. All rights reserved.
*   
*   文件名称：allTest.cpp
*   创 建 者：zt
*   创建日期：2020年03月12日
*   描    述：
*
================================================================*/


#include "gtest/gtest.h"
#include <iostream>
using namespace std;
int main(int argc, char* argv[]){
    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    return 0;
}
