//获得完美走位
//题目描述
//在第一人称射击游戏中，玩家通过键盘的 A、S、D、W 四个按键控制游戏人物分别向左、
//向后、向右、向前进行移动，从而完成走位。假设玩家每按动一次键盘，游戏人物会向某
//个方向移动一步，如果玩家在操作一定次数的键盘并且各个方向的步数相同时，此时游戏
//人物必定会回到原点，则称此次走位为完美走位。
//现给定玩家的走位（例如：ASDA）,请通过更换其中 一段连续走位的方式
//使得原走位能够变成一个完美走位。其中待更换的连续走位可以是相同长度的任何走位。
//请返回待更换的连续走位的最小可能长度。
//若果原走位本身是一个完美走位，则返回 0。输入描述
//输入为由键盘字母表示的走位 s，例如：ASDA
//输出描述
//输出为待更换的连续走位的最小可能长度

#include <gtest/gtest.h>
#include <unordered_map>
#include <climits>

using namespace std;

int min_replacement_length(const std::string &input_str) {
    // 初始化方向键计数字典
    std::unordered_map<char, int> direction_count = {{'W', 0}, {'A', 0}, {'S', 0}, {'D', 0}};

    // 统计输入字符串中每个方向键的出现次数
    for (char c : input_str) {
        direction_count[c]++;
    }

    // 初始化左右指针和结果变量
    int left = 0;
    int right = 0;
    int min_length = input_str.length();

    // 更新右指针对应的方向键计数
    direction_count[input_str[0]]--;

    while (true) {
        // 计算当前最大方向键计数
        int max_count = std::max({direction_count['W'], direction_count['A'], direction_count['S'], direction_count['D']});

        // 计算当前窗口长度和可替换的字符数
        int window_length = right - left + 1;
        int replaceable_chars = window_length;
        for (const auto &kv : direction_count) {
            replaceable_chars -= max_count - kv.second;
        }

        // 如果可替换字符数大于等于0且能被4整除，则更新结果变量
        if (replaceable_chars >= 0 && replaceable_chars % 4 == 0) {
            min_length = std::min(min_length, window_length);

            // 更新左指针并检查是否越界
            if (left < input_str.length()) {
                direction_count[input_str[left]]++;
                left++;
            } else {
                break;
            }
        } else {
            // 更新右指针并检查是否越界
            right++;
            if (right >= input_str.length()) {
                break;
            }
            direction_count[input_str[right]]--;
        }
    }

    return min_length;
}

TEST(HuaWeiOd, PerfectPostion)
{
    std::string input_str;
    std::cin >> input_str;
    std::cout << min_replacement_length(input_str) << std::endl;
}
