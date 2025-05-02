#include <iostream>
#include <gtest/gtest.h>
using namespace std;

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::GTEST_FLAG(filter) = "LeetCode.SubArray_209";
    return RUN_ALL_TESTS();
}
