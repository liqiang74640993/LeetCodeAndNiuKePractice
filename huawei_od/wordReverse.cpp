#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//单词倒叙
//题目描述
//输入单行英文句子，里面包含英文字母，空格以及,.?
//三种标点符号，请将句子内每个单词进行倒序，并输出倒序后的语句
//输入描述
//输入字符串 S，S 的长度 1≤N≤100
//输出描述
//输出逆序后的字符串

//1.std::isalpha 函数的主要功能是检查传入的字符是否为字母字符。这里的字母字符涵盖了大写字母（从 A 到 Z）和小写字母（从 a 到 z）。
//2.std::isdigit: is numer(0~9)
//3.std::reverse: 倒序
//4.getline:输入一行,不能直接使用std::cin,那么就读取空格就结束了
TEST(HuaWeiOd, WorkReverse)
{
    string s;
    std::getline(std::cin, s);
    std::cout << s << std::endl;
    bool isStart = true;
    vector<string> wordsVec;
    string word;
    for(auto iter = s.begin(); iter != s.end(); ++iter){
        if(std::isalpha(*iter)){//
            if(isStart){
                word = "";
                isStart = false;
            }
            word += *iter;
        }else{//
            if(!word.empty()){
                std::reverse(word.begin(),word.end());
                std::cout << word;
                word = "";
            }
            isStart = true;
            std::cout << *iter;
        }
    }

    if(!word.empty()){
        std::reverse(word.begin(),word.end());
        std::cout << word;
    }
     std::cout << std::endl;
}
