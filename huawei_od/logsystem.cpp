#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

//日志采集系统
//题目描述
//日志采集是运维系统的的核心组件。日志是按行生成，每行记做一条，由采集系统分批上
//报。
//如果上报太频繁，会对服务端造成压力；如果上报太晚，会降低用户的体验；如果一次上
//报的条数太多，会导致超时失败。
//为此，项目组设计了如下的上报策略：
//1、每成功上报一条日志，奖励 1 分
//2、每条日志每延迟上报 1 秒，扣 1 分
//3、积累日志达到 100 条，必须立即上报
//给出日志序列，根据该规则，计算首次上报能获得的最多积分数
//输入描述
//按时序产生的日志条数 T1,T2...Tn, 其中 1<=n<=1000, 0<=Ti<=100
//输出描述
//首次上报最多能获得的积分数


TEST(HuaWeiOd, LogSystem)
{
   string input;
   getline(cin, input);  // 从标准输入读取整行数据
   vector<string> logs;  // 用于存储日志条数的字符串向量
   string temp = "";     // 临时字符串变量，用于逐字符拼接日志条数
   for (int i = 0; i < input.length(); i++) {  // 遍历输入的每一个字符
       if (input[i] == ' ') {  // 遇到空格时，表示一个日志条数的结束
           logs.push_back(temp);  // 将当前拼接的字符串加入日志向量
           temp = "";  // 重置临时字符串变量
       } else {
           temp += input[i];  // 拼接字符
       }
   }
   logs.push_back(temp);  // 将最后一个日志条数加入日志向量

   int totalCount = 0;  // 累计日志总条数
   int maxScore = 0;    // 记录最大积分数
   for (int i = 0; i < logs.size(); i++) {  // 遍历每个时间点的日志
       int logCount = stoi(logs[i]);  // 将当前日志条数从字符串转换为整数
       if (logCount == 0) {  // 如果当前时间点日志条数为0，跳过该时间点
           continue;
       }

       totalCount += logCount;  // 累加日志总条数

       int score = 0;  // 当前时间点的积分
       for (int j = 0; j <= i; j++) {  // 计算当前时间点的积分
           if (totalCount > 100 && i == j) {  // 如果总日志条数超过100且当前为最后一个时间点
               score += logCount - (totalCount - 100);  // 计算积分，考虑超出100条的部分
           } else {
               score += stoi(logs[j]) - (i - j) * stoi(logs[j]);  // 正常积分计算，考虑延迟扣分
           }
       }

       if (score > maxScore) {  // 更新最大积分数
           maxScore = score;
       }

       if (totalCount >= 100) {  // 如果总日志条数达到或超过100，提前结束循环
           break;
       }
   }
   cout << maxScore << endl;  // 输出最大积分数
}

