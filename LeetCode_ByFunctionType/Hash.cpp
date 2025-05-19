#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

//给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的。

//示例 1:
//输入: s = "anagram", t = "nagaram"
//输出: true

//示例 2:
//输入: s = "rat", t = "car"
//输出: false

//提示:
//    1 <= s.length, t.length <= 5 * 104
//    s 和 t 仅包含小写字母

//进阶: 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？

bool isAnagram(string s, string t) {
    int hash[26];//26个小写字母
    int size_s = s.size();
    int size_t = t.size();
    if(size_t != size_s) return false;
    for(int i = 0; i <size_t; ++i){
        hash[s[i] - 'a']++;
        hash[t[i] - 'a']--;
    }
    for(int i = 0; i < 26; ++i){
        if(hash[i] != 0)
            return false;
    }
    return true;
}


//给定两个数组 nums1 和 nums2 ，返回 它们的  。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。
//示例 1：
//输入：nums1 = [1,2,2,1], nums2 = [2,2]
//输出：[2]

//示例 2：
//输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
//输出：[9,4]
//解释：[4,9] 也是可通过的

//提示：
//    1 <= nums1.length, nums2.length <= 1000
//    0 <= nums1[i], nums2[i] <= 1000


vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
{
   unordered_set<int> numsSet(nums1.cbegin(),nums2.cend()); //key-num,value-count
    int size2 = nums2.size();
    unordered_set<int> nums2Set;
    for(int i = 0; i < size2; ++i){
       if(numsSet.find(nums2[i]) != numsSet.cend()){
           nums2Set.insert(nums2[i]);
       }
    }
    return vector<int>(nums2Set.cbegin(),nums2Set.cend());
}


vector<int> twoSum(vector<int>& nums, int target) {
   //暴力法
//   int size = nums.size();
//   vector<int> res;
//   for(int i = 0; i < size; ++i){
//       int temp = target - nums[i];
//       for(int j = i+1; j < size; ++j){
//           if(temp == nums[j]){
//               res.emplace_back(i);
//               res.emplace_back(j);
//               return res;
//           }
//       }
//   }
//   return res;

   //map:select
   vector<int> result;
   unordered_map<int,int> map;//key:i,
   int size = nums.size();
   for(int i = 0; i < size; ++i){
      int temp = target - nums[i];//
      if(map.find(temp) == map.cend()){
          map.insert(pair(nums[i],i));
      }else{
          result.emplace_back(i);
          result.emplace_back(map[temp]);
          return result;
      }
   }
   return result;
}

//给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n ，请你计算有多少个元组 (i, j, k, l) 能满足：

//    0 <= i, j, k, l < n
//    nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0

//示例 1：
//输入：nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
//输出：2
//解释：
//两个元组如下：
//1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
//2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0

//示例 2：
//输入：nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
//输出：1

//  提示：
//    n == nums1.length
//    n == nums2.length
//    n == nums3.length
//    n == nums4.length
//    1 <= n <= 200
//    -228 <= nums1[i], nums2[i], nums3[i], nums4[i] <= 228
int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)
{
    std::unordered_map<int,int> map1,map2;
    int size1 = nums1.size();
    int size2 = nums2.size();
    for(int i = 0; i < size1; ++i){
        for(int j = 0; j < size2; ++j){
            ++map1[nums1[i] + nums2[j]];
        }
    }
    int size3 = nums3.size();
    int size4 = nums4.size();
    int result = 0;
    int temp = 0;
    for(int i = 0; i < size3; ++i){
        for(int j = 0; j < size4; ++j){
             temp = nums3[i] + nums4[j];
             auto iter = map1.find(-temp);
             if(iter != map1.cend()){
                 result += iter->second;
             }
        }
    }
    return result;
}


//第15题. 三数之和

//(opens new window)

//给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

//注意： 答案中不可以包含重复的三元组。

//示例：

//给定数组 nums = [-1, 0, 1, 2, -1, -4]，

//满足要求的三元组集合为： [ [-1, 0, 1], [-1, -1, 2] ]
vector<vector<int>> threeSum(vector<int>& nums) {
       vector<vector<int>> result;
       sort(nums.begin(),nums.end());
       int size = nums.size();
       for(int i = 0; i < size; ++i){
           if(nums[i] > 0) return result;
           int left = i + 1;
           int right =  size - 1;
           if(i > 0 && nums[i] == nums[i - 1])
               continue;
           while(left < right){
               int temp = nums[i] + nums[left] + nums[right];
               if(temp > 0)
                   right--;
               else if(temp < 0)
                   left++;
               else{
                   result.emplace_back(vector<int>{nums[i],nums[left],nums[right]});
                   while(right > left && nums[right - 1] == nums[right])
                       right--;
                   while(right > left && nums[left + 1] == nums[left])
                       left++;
                   left++;
                   right--;
               }
           }
       }
       return result;

//       sort(nums.begin(), nums.end());
//       // 找出a + b + c = 0
//       // a = nums[i], b = nums[left], c = nums[right]
//       for (int i = 0; i < nums.size(); i++) {
//           // 排序之后如果第一个元素已经大于零，那么无论如何组合都不可能凑成三元组，直接返回结果就可以了
//           if (nums[i] > 0) {
//               return result;
//           }
//           // 错误去重a方法，将会漏掉-1,-1,2 这种情况
//           /*
//           if (nums[i] == nums[i + 1]) {
//               continue;
//           }
//           */
//           // 正确去重a方法(这里去除重复的i，因为下面找到之后会紧缩左右指针，会得到所有当前i的组合值，
//           //而不需要再次使用下次循环在去判断)
//           if (i > 0 && nums[i] == nums[i - 1]) {
//               continue;
//           }
//           int left = i + 1;
//           int right = nums.size() - 1;
//           while (right > left) {
//               // 去重复逻辑如果放在这里，0，0，0 的情况，可能直接导致 right<=left 了，从而漏掉了 0,0,0 这种三元组
//               /*
//               while (right > left && nums[right] == nums[right - 1]) right--;
//               while (right > left && nums[left] == nums[left + 1]) left++;
//               */
//               if (nums[i] + nums[left] + nums[right] > 0) right--;
//               else if (nums[i] + nums[left] + nums[right] < 0) left++;
//               else {
//                   result.push_back(vector<int>{nums[i], nums[left], nums[right]});
//                   // 去重逻辑应该放在找到一个三元组之后，对b 和 c去重
//                   while (right > left && nums[right] == nums[right - 1])
//                       right--;
//                   while (right > left && nums[left] == nums[left + 1])
//                       left++;
//                   // 找到答案时，双指针同时收缩()
//                   right--;
//                   left++;
//               }
//           }

//       }
       return result;
   }

//第18题. 四数之和

//力扣题目链接

//(opens new window)

//题意：给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

//注意：

//答案中不可以包含重复的四元组。

//示例： 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
//满足要求的四元组集合为： [ [-1, 0, 0, 1], [-2, -1, 1, 2], [-2, 0, 0, 2] ]
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    for (int k = 0; k < nums.size(); k++) { //固定第一个数
        // 剪枝处理（注意，不能直接判断nums[k] > target就完事了，比如target = -5, nums[k] = -4 ）
        if (nums[k] > target && nums[k] >= 0) {
            break; // 这里使用break，统一通过最后的return返回
        }
        // 对nums[k]去重
        if (k > 0 && nums[k] == nums[k - 1]) {
            continue;
        }
        for (int i = k + 1; i < nums.size(); i++) {
            // 2级剪枝处理
            if (nums[k] + nums[i] > target && nums[k] + nums[i] >= 0) {
                break;
            }

            // 对nums[i]去重
            if (i > k + 1 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (right > left) {
                // nums[k] + nums[i] + nums[left] + nums[right] > target 会溢出
                if ((long) nums[k] + nums[i] + nums[left] + nums[right] > target) {
                    right--;
                // nums[k] + nums[i] + nums[left] + nums[right] < target 会溢出
                } else if ((long) nums[k] + nums[i] + nums[left] + nums[right]  < target) {
                    left++;
                } else {
                    result.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});
                    // 对nums[left]和nums[right]去重
                    while (right > left && nums[right] == nums[right - 1]) right--;
                    while (right > left && nums[left] == nums[left + 1]) left++;

                    // 找到答案时，双指针同时收缩
                    right--;
                    left++;
                }
            }

        }
    }
    return result;


//   vector<vector<int>> result;
//   sort(nums.begin(),nums.end());
//   int size = nums.size();
//   for(int i = 0; i < size; ++i){
//       for(int j = size- 1; j > i + 2; j--){
//           int left = i + 1;
//           int right = j - 1;
//           while(right > left){
//               int sum = nums[i] + nums[left] + nums[right] + nums[j];
//               if(sum > target){
//                   right--;
//               }
//               else if(sum < target){
//                   left++;
//               }else{
//                   result.emplace_back(vector<int>{nums[i],nums[left],nums[right],nums[j]});
//                   right--;
//                   left++;
//               }
//           }
//       }
//   }
//   int resultSize = result.size();
//   vector<vector<int>> res1;
//   for(int i = 0; i < resultSize - 1; ++i){
//       map<int,int> numMap;
//       ++numMap[result[i][0]];
//       ++numMap[result[i][1]];
//       ++numMap[result[i][2]];
//       ++numMap[result[i][3]];
//       bool flag = false;
//       for(int j = i + 1; j < resultSize; ++j){
//            map<int,int>tempMap(numMap);
//            for(int k = 0; k < 3; ++k){
//                auto iter = tempMap.find(result[j][k]);
//                if(iter == tempMap.cend() || iter->second == 0){
//                    //continue;
//                    break;
//                }else{
//                    iter->second--;
//                }
//            }
//            flag = true;
//            break;
//       }
//       if(flag){
//           res1.emplace_back(vector<int>{result[i][0],result[i][1],result[i][2],result[i][3]});
//       }
//   }

//   int res1Size = res1.size();
//   if(resultSize != 0 && res1Size == 0){
//       res1.emplace_back(vector<int>{result[0][0],result[0][1],result[0][2],result[0][3]});
//       res1Size = 1;
//   }
//   int count = 0;
//   for(int i = 0; i < res1Size;  ++i){
//       map<int,int> numMap;
//       ++numMap[res1[i][0]];
//       ++numMap[res1[i][1]];
//       ++numMap[res1[i][2]];
//       ++numMap[res1[i][3]];
//       for(int j = 0; j < 3; ++j){
//           auto iter = numMap.find(result[resultSize - 1][j]);
//           if( iter == numMap.cend() || iter->second == 0){ //
//               count++;
//               break;
//           }else{
//               iter->second --;
//           }
//       }
//   }
//   if(count == res1Size && count != 0){
//       res1.emplace_back(vector<int>{result[resultSize - 1][0],result[resultSize - 1][1],
//                                     result[resultSize - 1][2],result[resultSize - 1][3]});
//   }
//   return res1;
}

#include "stringUtil.h"

TEST(LeetCode, Hash)
{
    vector<int> vec;
    string res = "[-2,-1,-1,1,1,2,2]";
    //string res = "[1,0,-1,0,-2,2]";
    res = res.substr(1,res.length() - 2);
    bool flag = splitStringToArray(res,vec,',');
    if(!flag) return;
    fourSum(vec,0);
}
