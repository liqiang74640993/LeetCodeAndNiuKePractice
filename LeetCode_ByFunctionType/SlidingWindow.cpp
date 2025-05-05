#include <gtest/gtest.h>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;


//209. 长度最小的子数组
//已解答
//中等
//相关标签
//相关企业

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

int minSubArrayLen(int target, vector<int>& nums)
{
    //滑动窗口方法
    int left = 0;
    int length = nums.size();
    int right = 0;
    int sum = 0;
    int result = INT_MAX;
    for(right = 0; right != length; right++){
        sum += nums[right];
        while(sum >= target){
            result = std::min(right - left + 1, result);
            sum -= nums[left];
            left++;
        }
    }
    return result == INT_MAX ? 0:result;
}

TEST(LeetCode, SlidingWindow)
{
    vector<int> nums;
    nums.emplace_back(2);
    nums.emplace_back(3);
    nums.emplace_back(1);
    nums.emplace_back(2);
    nums.emplace_back(4);
    nums.emplace_back(3);
   std::cout << minSubArrayLen(7,nums) << std::endl;
}
