/*================================================================
*   Copyright (C) 2020 Sangfor Ltd. All rights reserved.
*   
*   文件名称：funcTest.cpp
*   创 建 者：zt
*   创建日期：2020年03月12日
*   描    述：
*
================================================================*/


#include "func.h"
#include <gtest/gtest.h>
TEST(addTest, addTest11){
    EXPECT_EQ(add(1,1), 2);
}
TEST(addTest, addTest12){
    EXPECT_EQ(add(1,2), 4);
}
TEST(addTest, addTest13){
    EXPECT_EQ(add(1,3), 4);
}

