#include <iostream>
#include <gtest/gtest.h>
using namespace std;

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::GTEST_FLAG(filter) = "LeetCode.String";
    return RUN_ALL_TESTS();
}
