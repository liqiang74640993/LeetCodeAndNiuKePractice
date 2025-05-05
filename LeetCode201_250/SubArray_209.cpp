
#include <gtest/gtest.h>
#include <vector>
#include <iostream>
#include <map>
#include <climits>
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
//    1 <= target <= 10de 9次方
//    1 <= nums.length <= 10的5次方
//    1 <= nums[i] <= 10 de 4次方

//进阶：
//    如果你已经实现 O(n) 时间复杂度的解法, 请尝试设计一个 O(n log(n)) 时间复杂度的解法。



static int minSubArrayLen(int target, vector<int>& nums)
{
    //暴力法,超出时间限制 ,letcode中没有通过,
//   int length = nums.size();
//   int sum = 0;
//   int smallLengthArray = 100000;
//   bool bFlag = false;
//   //form the first element to the last element
//   for(int i = 0; i < length; ++i){
//       sum = 0;
//       for(int j = i; j < length; j++){
//           sum += nums[j];
//           if(sum >= target){
//               if((j - i + 1) < smallLengthArray){
//                   smallLengthArray = j - i + 1;
//                   bFlag = true;
//               }
//               break;
//           }
//       }
//   }
//   if(bFlag)
//       return smallLengthArray;
//   return 0; //not exist;

    //滑动窗口方法
   int i = 0; //left
   int length = nums.size();
   int result = INT32_MAX;
   int min = 0;
   int sum = 0;
   for(int j = 0; j < length; ++j){
       sum += nums[j];
       while(sum >= target){
           min = j - i + 1;
           if(min < result){
               result = min;
           }
           sum -= nums[i++];
       }
   }
   return result == INT32_MAX ? 0 : result;
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
