//题目描述

//在一个狭小的路口，每秒只能通过一辆车，假设车辆的颜色只有 3 种，找出 N 秒内经过的最多颜色的车辆数量。

//三种颜色编号为0 ，1 ，2

//输入描述

//第一行输入的是通过的车辆颜色信息

//[0,1,1,2] 代表4 秒钟通过的车辆颜色分别是 0 , 1 , 1 , 2

//第二行输入的是统计时间窗，整型，单位为秒

//输出描述

//输出指定时间窗内经过的最多颜色的车辆数量。

//输入 	0 1 2 1
//3
//输出 	2
//说明 	在 3 秒时间窗内，每个颜色最多出现 2 次。例如：[1,2,1]
//输入 	0 1 2 1
//2
//输出 	1
//说明 	在 2 秒时间窗内，每个颜色最多出现1 次。

#include <gtest/gtest.h>
#include <vector>
#include "stringUtil.h"

using namespace std;

#define CAR_COLOR 3

TEST(HuaWeiOd, MostColorCar)
{
    int carColorCount[CAR_COLOR];
    memset(carColorCount,0,sizeof(int) * CAR_COLOR);//
    int secondSpace;//
    string inputColor;
    getline(std::cin,inputColor);
    vector<int> colorVec;
    splitStringToArray(inputColor,colorVec,' ');
    cin >> secondSpace;
    int length = colorVec.size();
    int temp = secondSpace;
    if(length < secondSpace)
        temp = length;
    int maxCar = 0;
    for(int i = 0; i < temp; ++i){
        if((++carColorCount[colorVec[i]]) > maxCar ){
            maxCar = carColorCount[colorVec[i]];
        }
    }
    int j = 0;
    for(int i = secondSpace; i < length; ++i)//i = 2,3
    {

        int index_j = colorVec[j];
        --carColorCount[colorVec[index_j]];//要先执行减操作,在执行加操作 ,否则可能会导致刚刚删除那位就是 要添加的元素

        int index_i = colorVec[i];
        if(++carColorCount[index_i] > maxCar)
            maxCar = carColorCount[index_i];
        j++;
    }

    std::cout << maxCar << std::endl;
}
