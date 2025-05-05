#include <gtest/gtest.h>
#include <vector>
#include <stringUtil.h>

using namespace  std;



//509.斐波那契数 （通常用 F(n) 表示）形成的序列称为 斐波那契数列 。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是：
//F(0) = 0，F(1) = 1
//F(n) = F(n - 1) + F(n - 2)，其中 n > 1
//给定 n ，请计算 F(n) 。

//示例 1：
//输入：n = 2
//输出：1
//解释：F(2) = F(1) + F(0) = 1 + 0 = 1

//示例 2：
//输入：n = 3
//输出：2
//解释：F(3) = F(2) + F(1) = 1 + 1 = 2

//示例 3：
//输入：n = 4
//输出：3
//解释：F(4) = F(3) + F(2) = 2 + 1 = 3
//提示：
//    0 <= n <= 30

int Fibonacci(int n)
{
    int f0 = 0, f1  = 1;
    if(n == 0) return 0;
    if(n == 1) return 1;
    int sum = 0;
    for(int i = 2; i <= n; ++i){
        sum = f0 + f1;
        f0 = f1;
        f1 = sum;
    }
    return sum;
}

//Leetcode 70 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
//每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
//示例 1：
//输入：n = 2
//输出：2
//解释：有两种方法可以爬到楼顶。
//1. 1 阶 + 1 阶
//2. 2 阶

//示例 2：
//输入：n = 3
//输出：3
//解释：有三种方法可以爬到楼顶。
//1. 1 阶 + 1 阶 + 1 阶
//2. 1 阶 + 2 阶
//3. 2 阶 + 1 阶

int climbStairs(int n)
{
    int f0 = 1, f1  = 2;
    if(n == 1) return 1;
    if(n == 2) return 2;
    int sum = 0;
    for(int i = 3; i <= n; ++i){
        sum = f0 + f1;
        f0 = f1;
        f1 = sum;
    }
    return sum;
}

//LeetCode：746: 给你一个整数数组 cost ，其中 cost[i] 是从楼梯第 i 个台阶向上爬需要支付的费用。一旦你支付此费用，即可选择向上爬一个或者两个台阶。

//你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。

//请你计算并返回达到楼梯顶部的最低花费。

//示例 1：

//输入：cost = [10,15,20]
//输出：15
//解释：你将从下标为 1 的台阶开始。
//- 支付 15 ，向上爬两个台阶，到达楼梯顶部。
//总花费为 15 。

//示例 2：

//输入：cost = [1,100,1,1,1,100,1,1,100,1]
//输出：6
//解释：你将从下标为 0 的台阶开始。
//- 支付 1 ，向上爬两个台阶，到达下标为 2 的台阶。
//- 支付 1 ，向上爬两个台阶，到达下标为 4 的台阶。
//- 支付 1 ，向上爬两个台阶，到达下标为 6 的台阶。
//- 支付 1 ，向上爬一个台阶，到达下标为 7 的台阶。
//- 支付 1 ，向上爬两个台阶，到达下标为 9 的台阶。
//- 支付 1 ，向上爬一个台阶，到达楼梯顶部。
//总花费为 6 。

//提示：

//    2 <= cost.length <= 1000
//    0 <= cost[i] <= 999


//dp[i] = min(dp[i-1]+cost[i-1],dp[i-2] + cost[i-2])
//[10,15]:代表2阶,需要从0阶或者1阶开始,从0阶花费10,从1阶开始花费15到达楼顶

int minCostClimbingStairs(vector<int>& cost)
{
    //dp0(初始代表0阶)代表i-2个数据的最小花费,dp1(初始代表1阶)代表i-1个数据的最小花费,dp代表第i个数据的最小花费
    int length = cost.size();
    if(length == 0 || length == 1) return 0;//0阶,1阶
    int dp0 = 0, dp1 = 0,dp = 0;
    for(int i = 2; i<= length; ++i){ //边界要使用length,主要是最后一步楼梯是没有显示出来的
        dp = min(dp0 + cost[i-2],dp1 +cost[i - 1]);
        dp0 = dp1;
        dp1 = dp;
    }
    return dp;
}

//LeetCode：62: 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

//机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。

//问总共有多少条不同的路径？

//示例 1：

//输入：m = 3, n = 7
//输出：28

//示例 2：

//输入：m = 3, n = 2
//输出：3
//解释：
//从左上角开始，总共有 3 条路径可以到达右下角。
//1. 向右 -> 向下 -> 向下
//2. 向下 -> 向下 -> 向右
//3. 向下 -> 向右 -> 向下

//示例 3：

//输入：m = 7, n = 3
//输出：28

//示例 4：

//输入：m = 3, n = 3
//输出：6


//提示：

//    1 <= m, n <= 100
//    题目数据保证答案小于等于 2 * 109


//m:line, n:col
int uniquePaths(int m, int n)
{
    map<pair<int,int>,int> cells;
    //初始化第一列的所有行的数据为1
    for(int i = 0; i < m; ++i){
       cells[pair(i,0)] = 1;
    }
    //初始化第一行的所有列的数据为1
    for(int j = 0; j < n; ++j){
        cells[pair(0,j)] = 1;
    }
    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            cells[pair(i,j)] = cells[pair(i-1,j)] + cells[pair(i,j-1)];
        }
    }
    return cells[pair(m-1,n-1)];
}


//给定一个 m x n 的整数数组 grid。一个机器人初始位于 左上角（即 grid[0][0]）。机器人尝试移动到 右下角（即 grid[m - 1][n - 1]）。机器人每次只能向下或者向右移动一步。

//网格中的障碍物和空位置分别用 1 和 0 来表示。机器人的移动路径中不能包含 任何 有障碍物的方格。

//返回机器人能够到达右下角的不同路径数量。

//测试用例保证答案小于等于 2 * 10 de 9 cifang 。

//输入：obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
//输出：2
//解释：3x3 网格的正中间有一个障碍物。
//从左上角到右下角一共有 2 条不同的路径：
//1. 向右 -> 向右 -> 向下 -> 向下
//2. 向下 -> 向下 -> 向右 -> 向右

//obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]] -正中间有一个障碍物。
//obstacleGrid 的每个元素是一行,外部代表行的个数
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
    //
    int lines = obstacleGrid.size();
    if(lines == 0){ //not correct param
        return 0;
    }
    int cols = obstacleGrid[0].size();
    if(cols == 0){
        return 0;
    }
    //特殊情况判断,开始点和结束点有障碍物,则代表无路径
    if(obstacleGrid[0][0] == 1 || obstacleGrid[lines - 1][cols - 1] == 1)
        return 0;

    map<pair<int,int>,int> cells;
    //初始化第一列的所有行的数据为1,障碍物后面的行都不初始化
    for(int i = 0; i < lines; ++i){
       if(obstacleGrid[i][0])
           break;
       cells[pair(i,0)] = 1;
    }
    //初始化第一行的所有列的数据为1,障碍物后面的列都不初始化
    for(int j = 0; j < cols; ++j){
        if(obstacleGrid[0][j] == 1){
            break;
        }
        cells[pair(0,j)] = 1;
    }
    for(int i = 1; i < lines; i++){
        for(int j = 1; j < cols; j++){
            if(obstacleGrid[i][j] == 0){//如果存在障碍物,则不能设置
                 cells[pair(i,j)] = cells[pair(i-1,j)] + cells[pair(i,j-1)];
            }
        }
    }
    return cells[pair(lines-1,cols-1)];
}

//给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。
//返回 你可以获得的最大乘积 。

//示例 1:
//输入: n = 2
//输出: 1
//解释: 2 = 1 + 1, 1 × 1 = 1。

//示例 2:
//输入: n = 10
//输出: 36
//解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。


//提示:
//    2 <= n <= 58

//- dp[i]:对数字i进行拆分,的到拆分数字的最大乘积
//- 递推公式: dp[i] = max(dp[i], j *(i-j), j * dp[i-j]);//dp[i-j]对i-j继续进行拆分,dp[i]:不拆分, j *(i - j):拆分1次,
//注:对j * dp[i-j]而言 ,拆分i-j就可以了,不需要在对j进行拆分,因为拆分i-j就可以包含拆分j的情况.举例:
//6 = 1 + 5 , 6 = 2 + 4 ,6 = 3 + 3, 6 = 4 + 2, 6 = 5 + 1(i-j依次为5到1可以包含所有的情况)
//- 初始化:dp[0] = 0,无意义,dp[1] = 0,无意义, dp[2] = 1 * 1 = 1.
//- 遍历顺序:从前往后遍历
//- 打印数组:用于调试

int integerBreak(int n)
{
   map<int,int> dpMaps;
   dpMaps[2] = 1;
   int dp;
   for(int i = 3; i <= n; ++i){
//       dp = dpMaps[i];
     // for(int j = 1; j < i; ++j){ // j <= i/2( j < i 可以优化,因为比如 i = 6, 一般分割 1 * 5, 2 * 4, 3 * 3 即可,并不需要在去分割为4 * 2 , 5 * 1)
      for(int j = 1; j <= i/2; ++j){
         dp = dpMaps[i];// 不能写在外层循环中,因为每次比较,都要和未分割进行比较
         dpMaps[i] = max(j * (i - j), j * dpMaps[i-j]);
         dpMaps[i] = max(dp,dpMaps[i]);
      }
   }
   return dpMaps[n];
}

int numTrees(int n)
{
    int dp1 = 1;
    int dp2 = 4;
    if(n == 1) return 1;
    if(n == 2) return 4;
    int dp = 0;
    for(int i = 3; i <= n; ++i){
        dp = dp1 + dp2;
        dp1 = dp2;
        dp2 = dp;
    }
    return dp;
}


TEST(LeetCode, DP1)
{
//   int n = 0;
//   std::cout << "Fibonacci n:";
//   cin >> n;
//   std::cout << Fibonacci(n) << std::endl;

//   std::cout << "ClimbStairs n:";
//   cin >>n;

//   std::cout << "minCostClimbingStairs:";
//   std::vector<int> cost; //[1,100,1,1,1,100,1,1,100,1]    [10,15,20]
//   string costVecStr;
//   getline(std::cin,costVecStr);
//   costVecStr = costVecStr.substr(1,costVecStr.length() - 2);
//   splitStringToArray(costVecStr, cost, ',');
//   std::cout << minCostClimbingStairs(cost);

 // std::cout << uniquePaths(7,3) << endl;

//  vector<vector<int>> obstacleGrid;
//  vector<int> lines;//[0,0,0],[0,1,0],[0,0,0]
//  lines.emplace_back(0);
//  lines.emplace_back(0);
//  lines.emplace_back(0);
//  obstacleGrid.emplace_back(lines);
//  lines.clear();
//  lines.emplace_back(0);
//  lines.emplace_back(1);
//  lines.emplace_back(0);
//  obstacleGrid.emplace_back(lines);
//  lines.clear();
//  lines.emplace_back(0);
//  lines.emplace_back(0);
//  lines.emplace_back(0);
//  obstacleGrid.emplace_back(lines);
//  std::cout << uniquePathsWithObstacles(obstacleGrid) << endl;

 // std::cout << integerBreak(10) << std::endl;
   std::cout << numTrees(2) << std::endl;
}
