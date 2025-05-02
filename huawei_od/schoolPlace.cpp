#include <gtest/gtest.h>
#include <string>
#include <iostream>

using namespace std;
//学校的位置
//题目描述
//为了解决新学期学生暴涨的问题，小乐村要建所新学校。考虑到学生上学安全问题，需要
//所有学生家到学校距离最短。
//假设学校和所有的学生家，走在一条直线上。
//请问，学校要建在什么位置，能使得学校到各个学生家的距离之和最短？
//输入描述
//输入的第一行是一个整数 N（1<=N<=1000），表示有 N 户家庭。
//输入的第二行是一个属组 （0<=
//<=10000），表示每户家庭的位置，所有家庭的位置都不相同。
//输出描述
//输出一行，一个整数，表示你确定的学校位置。如有多个位置相同，则输出值最小的位置
//。

TEST(HuaWeiOd, SchoolPlace)
{
    int n;
    std::cin >> n;
    std::vector<int> positions(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> positions[i];
    }
    // 对家庭位置进行排序
    std::sort(positions.begin(), positions.end());
    int schoolLocation;
    if (n % 2 == 1) {
        // 家庭数量为奇数，学校位置为中间位置
        schoolLocation = positions[n / 2];
    } else {
        // 家庭数量为偶数，学校位置为中间两个位置中较小的那个
        schoolLocation = positions[n / 2 - 1];
    }
    std::cout << schoolLocation << std::endl;
}
