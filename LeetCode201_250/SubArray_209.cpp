
#include <gtest/gtest.h>
#include <vector>
#include <iostream>
#include <map>
#include "stringUtil.h"

using namespace std;

//给定一个含有 n 个正整数的数组和一个正整数 target 。

//找出该数组中满足其总和大于等于 target 的长度最小的

// [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。
//示例 1：
//输入：target = 7, nums = [2,3,1,2,4,3]
//输出：2
//解释：子数组 [4,3] 是该条件下的长度最小的子数组。

//示例 2：
//输入：target = 4, nums = [1,4,4]
//输出：1

//示例 3：
//输入：target = 11, nums = [1,1,1,1,1,1,1,1]
//输出：0

//提示：
//    1 <= target <= 109
//    1 <= nums.length <= 105
//    1 <= nums[i] <= 104

//进阶：
//    如果你已经实现 O(n) 时间复杂度的解法, 请尝试设计一个 O(n log(n)) 时间复杂度的解法。


int minSubArrayLen(int target, vector<int>& nums)
{
   int result = 0;

   return result;
}

TEST(LeetCode, SubArray_209)
{
    int target = 0;
    std::vector<int> nums;
    string numsStr;
    getline(std::cin,numsStr);
    int length = numsStr.length();
    numsStr = numsStr.substr(1,length - 2);
    bool flag = splitStringToArray(numsStr,nums,',');
    if(!flag) return;
    cin >> target;
    std::cout << minSubArrayLen(target,nums) << std::endl;
}
