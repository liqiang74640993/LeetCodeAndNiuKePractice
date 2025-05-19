#include <gtest/gtest.h>
#include <vector>
#include <iostream>
#include <map>

//题目描述

//给定一个数组nums，将元素分为若干个组，使得每组和相等，求出满足条件的所有分组中，组内元素和的最小值。

//输入描述

//第一行输入 m
//接着输入m个数，表示此数组nums
//数据范围：1<=m<=50, 1<=nums[i]<=50

//输出描述

//最小拆分数组和

//用例
//输入 	7
//4 3 2 3 5 2 1
//输出 	5
//说明

//可以等分的情况有：

//4 个子集（5），（1,4），（2,3），（2,3）

//2 个子集（5, 1, 4），（2,3, 2,3）

//但最小的为5。


using namespace std;

static bool partition(vector<int> link, int index, vector<int> buckets, int subSum)
{
    if(index == link.size())
        return true;
    int select = link[index];
    for(int i = 0; i < buckets.size();i++){
        if(i > 0 && buckets[i] == buckets[i - 1])
            continue;
        if(select  + buckets[i] <= subSum){
            buckets[i] += select;
            if(partition(link,index + 1,buckets,subSum))
                return true;
            buckets[i] -= select;
        }
    }
    return false;
}

static bool canPartitionMSubsets(vector<int>link, int sum, int m){
    if(sum % m != 0) return false;
    int subSum = sum / m;
    if(subSum < link[0]) return false;
    //如果元素本身就是分数组之和，则直接remove
    while(link.size() > 0 && link[0] == subSum){
        link.erase(link.begin());
        m--;
    }
    vector<int> buckets(m);
    //
    return partition(link, 0,buckets,subSum);
}

static int getResult(vector<int> &vec, int m){
    sort(vec.begin(),vec.end(),std::greater<int>());
    int sum = 0;
    for(auto iter: vec){
        sum += iter;
    }

    while(m > 0){
        //分组 越大，则分组和越小，如果元素可以使用某个分组 ，则返回，
        //比如数组的元素和为20，如果分组越多，则每个分组的元素就越小
        if(canPartitionMSubsets(vec,sum,m)){//
            return sum/m;
        }
        m--;
    }
    return sum;
}

TEST(HuaWeiOd, EqualSubArrayMinSum)
{
    int m;
    std::cin >> m;
    vector<int> vec;
    int temp;
    for(auto i = 0; i < m; i++){
        cin >> temp;
        vec.emplace_back(temp);
    }
    std::cout << getResult(vec,m) << std::endl;
}
