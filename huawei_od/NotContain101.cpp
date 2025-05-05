//题目描述

//小明在学习二进制时，发现了一类不含 101的数，也就是：

//将数字用二进制表示，不能出现 101 。
//现在给定一个整数区间 [l,r] ，请问这个区间包含了多少个不含 101 的数？

//输入描述

//输入的唯一一行包含两个正整数 l， r（ 1 ≤ l ≤ r ≤ 10^9）。

//输出描述

//输出的唯一一行包含一个整数，表示在 [l,r] 区间内一共有几个不含 101 的数。

//用例
//输入 	1 10
//输出 	8
//说明 	区间 [1,10] 内， 5 的二进制表示为 101 ，10的二进制表示为 1010 ，因此区间 [ 1 , 10 ] 内有 10−2=8 个不含 101的数。

//输入 	10 20
//输出 	7
//说明 	区间 [10,20] 内，满足条件的数字有 [12,14,15,16,17,18,19] 因此答案为 7。


#include <gtest/gtest.h>
#include <vector>
#include <string>

using namespace std;

int tenToBinary(int num, string &s)
{
    int count  = 0;
    int temp1;
    while(num > 1){
        temp1 = num % 2;
        if(temp1 == 1){
            count++;
            s.insert(0,"1");
        }else {
            count++;
            s.insert(0,"0");
        }
        num = num / 2;
    }
    if(num == 1){
        count++;
        s.insert(0,"1");
    }
    return count;
}

TEST(HuaWeiOd, NotContain101)
{
    int l =0,r = 0;
    std::cin >> l >> r;
    if(0 < r && r < 10){
        std::cout << 1 << std::endl;
        return;
    }
    string l1,r1;
    int lowCount = tenToBinary(l,l1);
    int highCount = tenToBinary(r,r1);
    r1 = "1000101";
    if(highCount >3){

    }else{

    }
    int a = 0;
    std::cout << a << std::endl;
}
