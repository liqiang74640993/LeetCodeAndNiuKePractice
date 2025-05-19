#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include "stringUtil.h"

using namespace std;

//LeetCode 455
//假设你是一位很棒的家长，想要给你的孩子们一些小饼干。但是，每个孩子最多只能给一块饼干。
//对每个孩子 i，都有一个胃口值 g[i]，这是能让孩子们满足胃口的饼干的最小尺寸；并且每块饼干 j，
//都有一个尺寸 s[j] 。如果 s[j] >= g[i]，我们可以将这个饼干 j 分配给孩子 i ，这个孩子会得到满足。你的目标是满足尽可能多的孩子，并输出这个最大数值。


//示例 1:
//输入: g = [1,2,3], s = [1,1]
//输出: 1
//解释:
//你有三个孩子和两块小饼干，3 个孩子的胃口值分别是：1,2,3。
//虽然你有两块小饼干，由于他们的尺寸都是 1，你只能让胃口值是 1 的孩子满足。
//所以你应该输出 1。

//示例 2:
//输入: g = [1,2], s = [1,2,3]
//输出: 2
//解释:
//你有两个孩子和三块小饼干，2 个孩子的胃口值分别是 1,2。
//你拥有的饼干数量和尺寸都足以让所有孩子满足。
//所以你应该输出 2。

int findContentChildren(vector<int>& g, vector<int>& s)
{
    sort(g.begin(),g.end());
    sort(s.begin(),s.end());
    int result = 0;
    int sindex = s.size() - 1;
    for(int i = g.size() - 1; i >= 0; i--){
        if(sindex >= 0 && s[sindex] >= g[i]){//剩余最大的饼干面积满足某个小孩的胃口
            result++;
            --sindex;
        }
    }
    return result;
}

//LeetCode 376. 摆动序列
//如果连续数字之间的差严格地在正数和负数之间交替，则数字序列称为 摆动序列 。第一个差（如果存在的话）可能是正数或负数。仅有一个元素或者含两个不等元素的序列也视作摆动序列。
//    例如， [1, 7, 4, 9, 2, 5] 是一个 摆动序列 ，因为差值 (6, -3, 5, -7, 3) 是正负交替出现的。
//    相反，[1, 4, 7, 2, 5] 和 [1, 7, 4, 5, 5] 不是摆动序列，第一个序列是因为它的前两个差值都是正数，第二个序列是因为它的最后一个差值为零。
//子序列 可以通过从原始序列中删除一些（也可以不删除）元素来获得，剩下的元素保持其原始顺序。
//给你一个整数数组 nums ，返回 nums 中作为 摆动序列 的 最长子序列的长度 。



//示例 1：
//输入：nums = [1,7,4,9,2,5]
//输出：6
//解释：整个序列均为摆动序列，各元素之间的差值为 (6, -3, 5, -7, 3) 。

//示例 2：
//输入：nums = [1,17,5,10,13,15,10,5,16,8]
//输出：7
//解释：这个序列包含几个长度为 7 摆动序列。
//其中一个是 [1, 17, 10, 13, 10, 16, 8] ，各元素之间的差值为 (16, -7, 3, -3, 6, -8) 。

//示例 3：
//输入：nums = [1,2,3,4,5,6,7,8,9]
//输出：2

int wiggleMaxLength(vector<int>& nums)
{
    int size = nums.size();
    if(size == 1) return 1;
    if(size == 2){
        if(nums[0] == nums[1]) return 1;
        else
            return 2;
    }
    int result = 1;
    int prediff = 0;
    int curdiff = 0;
    for(int i = 0; i < size - 1; ++i){
        curdiff = nums[i + 1] - nums[i];
        if((prediff <= 0 && curdiff > 0) || (prediff >= 0 && curdiff < 0)){
            result++;
            prediff = curdiff;
        }
    }
    return result;
}

#include <climits>

//给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

//示例:

//    输入: [-2,1,-3,4,-1,2,1,-5,4]
//    输出: 6
//    解释:  连续子数组  [4,-1,2,1] 的和最大，为  6。
int maxSubArray(vector<int>& nums)
{
    int size = nums.size();

    //暴力法,超出时间限制
//    int max = 0;
//    vector<int> tempVec;
//    for(int i = 0; i < size; ++i){
//        int temp = nums[i];
//        tempVec.emplace_back(nums[i]);
//        for(int j = i+1; j < size; ++j){
//            temp += nums[j];
//            tempVec.emplace_back(temp);
//        }
//        sort(tempVec.begin(),tempVec.end(),std::greater<int>());
//        if(tempVec[0] > max)
//            max = tempVec[0];
//        tempVec.clear();
//    }
//    return max;

    //
    int sum = 0;
    int max = INT_MIN;
    for(int i = 0; i < size; ++i){
        if(sum + nums[i] <= nums[i]){
            sum  = nums[i];
        }else{
            sum += nums[i];
        }
        if(max < sum){
            max = sum;
        }
    }
    return max;
}

//122. 买卖股票的最佳时机 II
//给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。
//在每一天，你可以决定是否购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。
//返回 你能获得的 最大 利润 。


//示例 1：
//输入：prices = [7,1,5,3,6,4]
//输出：7
//解释：在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4。
//随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6 - 3 = 3。
//最大总利润为 4 + 3 = 7 。

//示例 2：
//输入：prices = [1,2,3,4,5]
//输出：4
//解释：在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4。
//最大总利润为 4 。

//示例 3：
//输入：prices = [7,6,4,3,1]
//输出：0
//解释：在这种情况下, 交易无法获得正利润，所以不参与交易可以获得最大利润，最大利润为 0

int maxProfit(vector<int>& prices)
{
    int size = prices.size();
    if(size == 0 || size == 1)
        return 0;
    int max = 0;
    bool flag = false;
    for(int i = 0; i < size - 1; ++i){
        if(flag){
            max += prices[i];
            flag = false;
        }
        if(prices[i + 1] > prices[i]){//
            max -= prices[i];
            flag = true;
        }
    }
    if(flag){
        max += prices[size-1];//
    }
    return max;
}



TEST(LeetCode, Greed)
{
    vector <int> vec;
    string res = "[1,2,3,4,5]";
    res = res.substr(1,res.length() - 2);
    bool flag = splitStringToArray(res,vec,',');
    if(!flag) return;
    maxProfit(vec);


   // maxSubArray(vec);



//    g.emplace_back(1);
//    g.emplace_back(2);
//    g.emplace_back(3);

//    s.emplace_back(3);
//    findContentChildren(g,s);
}
