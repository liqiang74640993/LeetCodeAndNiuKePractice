#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


//任务混部
//题目描述
//公司创新实验室正在研究如何最小化资源成本，最大化资源利用率，请你设计算法帮他们
//解决一个任务混部问题：有 taskNum 项任务，每个任务有开始时间（startTime
//），结束时间（endTime），并行度(parallelism)三个属性，并行度是指这个任务运行时将
//会占用的服务器数量，一个服务器在每个时刻可以被任意任务使用但最多被一个任务占用
//，任务运行完会立即释放（结束时刻不占用）。任务混部问题是指给定一批任务，让这批
//任务由同一批服务器承载运行，请你计算完成这批任务混部最少需要多少服务器，从而最
//大化控制资源成本。
//输入描述
//第一行输入为 taskNum，表示有 taskNum 项任务
//接下来 taskNum 行，每行三个整数，表示每个任务的开始时间（startTime
//），结束时间（endTime），并行度(parallelism)
//输出描述
//一个整数，表示最少需要的服务器数量
TEST(HuaWeiOd, TaskMixedScheduling)
{
    int taskNum = 0, startTime = 0, endTime = 0, parallelism = 0;
    std::cin >> taskNum;
    vector<pair<int,int>> tasks;
    for(int i = 0; i < taskNum; ++i){
        cin >> startTime >> endTime >> parallelism;
        tasks.emplace_back(startTime, parallelism);
        tasks.emplace_back(endTime, -parallelism);
    }
    sort(tasks.begin(),tasks.end());
    int maxServer = 0,server = 0;
    for(auto &task: tasks){
        server += task.second;
        maxServer = max(maxServer,server);
    }
    std::cout << maxServer << std::endl;
}
