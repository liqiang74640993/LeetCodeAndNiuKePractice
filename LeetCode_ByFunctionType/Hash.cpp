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


TEST(LeetCode, Hash)
{

}
