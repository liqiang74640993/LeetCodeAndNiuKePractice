#include <gtest/gtest.h>
#include <vector>
#include <iostream>
#include <map>


using namespace std;

//题目描述
//某公司研发了一款高性能AI处理器。每台物理设备具备8颗AI处理器，编号分别为0、1、2、3、4、5、6、7。
//编号0-3的处理器处于同一个链路中，编号4-7的处理器处于另外一个链路中，不通链路中的处理器不能通信。
//如下图所示。现给定服务器可用的处理器编号数组array，以及任务申请的处理器数量num，找出符合下列亲和性调度原则的芯片组合。
//如果不存在符合要求的组合，则返回空列表。

//亲和性调度原则：
//-如果申请处理器个数为1，则选择同一链路，剩余可用的处理器数量为1个的最佳，其次是剩余3个的为次佳，然后是剩余2个，最后是剩余4个。
//-如果申请处理器个数为2，则选择同一链路剩余可用的处理器数量2个的为最佳，其次是剩余4个，最后是剩余3个。
//-如果申请处理器个数为4，则必须选择同一链路剩余可用的处理器数量为4个。
//-如果申请处理器个数为8，则申请节点所有8个处理器。

//提示：
//任务申请的处理器数量只能是1、2、4、8。
//编号0-3的处理器处于一个链路，编号4-7的处理器处于另外一个链路。
//处理器编号唯一，且不存在相同编号处理器。
//输入描述
//输入包含可用的处理器编号数组array，以及任务申请的处理器数量num两个部分。
//第一行为array，第二行为num。例如：
//[0, 1, 4, 5, 6, 7]
//1
//表示当前编号为0、1、4、5、6、7的处理器可用。任务申请1个处理器。
//0 <= array.length <= 8
//0 <= array[i] <= 7
//num in [1, 2, 4, 8]

//输出描述
//输出为组合列表，当array=[0，1，4，5，6，7]，num=1 时，输出为[[0], [1]]。

void showResult(vector<int> process)
{
    std::cout << "[";
    int maxIndex  = process.size() - 1;
    for(int i = 0; i < maxIndex; ++i){
        std::cout << "[" << process[i] <<  "]";
        std::cout << ",";
    }
    std::cout << "[" << process[maxIndex] << "]]"  << std::endl;
}

TEST(HuaWeiOd, CpuAllocate)
{
    vector<int> inProcess;
    string inputArray;
    std::cin >>inputArray;
    int len = inputArray.length();
    inputArray = inputArray.substr(1,len - 2);
    for(auto iter =inputArray.begin(); iter != inputArray.end(); ++iter)
    {
        if(std::isdigit(*iter)){
            inProcess.emplace_back(*iter -48);
        }
    }
    vector<int> firstProcess,secondProcess;
    for(auto iter: inProcess){
        if(iter < 4){
            firstProcess.emplace_back(iter);
        }else{
            secondProcess.emplace_back(iter);
        }
    }
    int num = 0;
    std::cin >> num;
    int firstSize = firstProcess.size();
    int secondSize = secondProcess.size();
    switch (num) {
    case 1:
        if(firstSize == 1){
            showResult(firstProcess);
        }else if(secondSize == 1){
            showResult(secondProcess);
        }else if(firstSize == 3){
            showResult(firstProcess);
        }else if(secondSize == 3){
            showResult(secondProcess);
        }else if(firstSize == 2){
            showResult(firstProcess);
        }else if(secondSize == 2){
            showResult(secondProcess);
        }else if(firstSize == 4){
             showResult(firstProcess);
        }else if(secondSize == 4){
            showResult(secondProcess);
        }else{
            std::cout << "[]";
        }
        break;
    case 2:
        if(firstSize == 2){
            showResult(firstProcess);
        }else if(secondSize == 2){
            showResult(secondProcess);
        }else if(firstSize == 4){
             showResult(firstProcess);
        }else if(secondSize == 4){
            showResult(secondProcess);
        }else if(firstSize == 3){
            showResult(firstProcess);
        }else if(secondSize == 3){
             showResult(secondProcess);
        }else{
            std::cout << "[]";
        }
        break;
    case 4:
        if(firstSize < 4 && secondSize <4){
            std::cout << "[]";
        }else if(firstSize == 4){
            showResult(firstProcess);

        }else{
            showResult(secondProcess);
        }
        break;
    case 8:
        if(firstSize + secondSize != 8){
            std::cout << "[]" << std::endl;
        }else{
            std::cout <<"[[0],[1],[2],[3],[4],[5],[6],[7]]" << std::endl;
        }
        break;
    }
}
