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

//return: binary bit count
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
    if(num == 1){//最高位为1
        count++;
        s.insert(0,"1");
    }
    return count;
}

#include <cmath>

TEST(HuaWeiOd, NotContain101)
{
    int l =0,r = 0;
    std::cin >> l >> r;
    if(r < 5){
        std::cout << r -l + 1 << std::endl;
        return;
    }
    if(r == 5){
        std::cout << r -l << std::endl;
        return;
    }
    string l1,r1;
    int lowCount = tenToBinary(l-1,l1);
    int highCount = tenToBinary(r,r1);
    string left3 = l1.substr(0,3);
    string right3 = r1.substr(0,3);
    string leftlow;
    if(lowCount - 3 > 0){
        leftlow  = l1.substr(3,lowCount - 3);
    }
    string rightlow = r1.substr(3,highCount -3);
    if(left3 != "101" && left3 != "111" && left3 != "110"){
        lowCount--;
    }
    if(right3 != "101" && right3 != "111" && right3 != "110"){
        highCount--;
    }

    int contain101 = 0;
    //计算右边数字除最高位所有低位的所有包含101的数字
    for(int i = 3; i < highCount; ++i){
       for(int j = 0; j <= i - 3; ++j){
           contain101 += pow(2,j);
       }
    }
    //计算右边数字最高位为101的情况
    contain101++; //00
    int sizer = rightlow.size();
    for(int i = 0; i < sizer; ++i){
        if(rightlow[i] == '1'){
            contain101 += pow(2,sizer-i-1);
        }
    }
    if(lowCount >= 3){ //要判断左边的数是否超过5
        for(int i = 3; i < lowCount; ++i){
            for(int j = 0; j <= i - 3; ++j){
                contain101 -= pow(2,j);
            }
        }
        if( std::atoi(leftlow.c_str()) == 0){
            contain101--;
        }else{
            int sizel = leftlow.size();
            for(int i = 0; i < sizel; ++i){
                if(leftlow[i] == '1'){
                    contain101 -= pow(2,sizel-i-1);
                }
            }
        }
    }
    int nums = r - l + 1;
    nums -= contain101;
    std::cout <<  nums << std::endl;
}
