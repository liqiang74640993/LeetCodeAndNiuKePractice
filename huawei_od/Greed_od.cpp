//贪心的题目类型

#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include  <queue>

using namespace std;

//华为OD机试 - 租车骑绿岛（Java & JS & Python）
//题目描述

//部门组织绿岛骑行团建活动。租用公共双人自行车，每辆自行车最多坐两人，最大载重M。
//给出部门每个人的体重，请问最多需要租用多少双人自行车。

//输入描述
//第一行两个数字m、n，分别代表自行车限重，部门总人数。
//第二行，n个数字，代表每个人的体重，体重都小于等于自行车限重m。
//    0<m<=200
//    0<n<=1000000

//输出描述
//最小需要的双人自行车数量。

//用例
//输入 	3 4
//3 2 2 1
//输出 	3
//说明 	无

void rentCar()
{
    int m,n;
    std::cin >> m >> n;
    vector<int> vec;
    int temp;
    for(int i = 0; i < n; ++i){
        std::cin >> temp;
        vec.emplace_back(temp);
    }
    sort(vec.begin(),vec.end());
    int length = vec.size();
    int result = length;
    vector<int> tempVec;
    while(length > 0){
        bool flag = false;
        for(int j = 1; j < length; ++j){
            //贪心,找出最大重量是否可以和其他重量构成一个车
            if(vec[0] + vec[j] <= m && !flag){
                result--;
                flag = true;
            }else{
                tempVec.emplace_back(vec[j]);
            }
        }
        vec = tempVec;
        length = vec.size();
        if(length == 1){
            break;
            result--;
        }
        tempVec.clear();
    }
    std::cout << result << std::endl;
}

TEST(HuaWeiOd, Greed)
{
    //rentCar();
    priority_queue<int> priv;
    priv.push(3);
    priv.push(2);
    priv.push(4);
    priv.push(1);
    int top = priv.top();
    priv.pop();
    std::cout << top << std::endl;

}
