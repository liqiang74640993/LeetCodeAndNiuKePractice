//题目描述

//给定一个字符串s，s包括以空格分隔的若干个单词，请对s进行如下处理后输出：
//1、单词内部调整：对每个单词字母重新按字典序排序
//2、单词间顺序调整：
//1）统计每个单词出现的次数，并按次数降序排列
//2）次数相同，按单词长度升序排列
//3）次数和单词长度均相同，按字典升序排列

//请输出处理后的字符串，每个单词以一个空格分隔。

//输入描述

//一行字符串，每个字符取值范围：[a-zA-z0-9]以及空格，字符串长度范围：[1，1000]

//输出描述

//输出处理后的字符串，每个单词以一个空格分隔。

//用例
//输入 	This is an apple
//输出 	an is This aelpp
//说明 	无
//输入 	My sister is in the house not in the yard
//输出 	in in eht eht My is not adry ehosu eirsst
//说明 	无

#include <string>
#include <algorithm>
#include <gtest/gtest.h>

using namespace std;

//先按照长度升序,在按照字母表排序
bool compareStringLengthAndalphabetical(const string &a, const string &b)
{
    if (a.length() != b.length()) {
            return a.length() < b.length();
     }
    return a < b;
}

TEST(HuaWeiOd, StringReRangeAndReOrder)
{
    //获取单词,对每个单词字母重新按字典序排序,放入到集合中,
    string str;
    getline(std::cin, str);
    int len = str.length();
    int start = 0;
    bool bFlag = true;
    string word;
    int wordLen = 0;
    map<string,int> mapWords;
    int i = 0;
    for(i = 0; i < len; ++i){
        if(!std::isblank(str[i])){
            if(bFlag){
                start = i;
                bFlag = false;
            }
        }else{//index i is blank
            if(start != -1){
                wordLen = i - start;
                word = str.substr(start,wordLen);
                sort(word.begin(),word.end());
                if(mapWords.find(word) == mapWords.end()){
                    mapWords[word] = 1;
                }else{
                    mapWords[word]++;
                }
                start = -1;
                bFlag = true;
            }
        }
    }
    if(start != -1){
        word = str.substr(start,i - start);
        sort(word.begin(),word.end());
        if(mapWords.find(word) == mapWords.end()){
            mapWords[word] = 1;
        }else{
            mapWords[word]++;
        }
    }

    //
    //找到次数最多的,如果只有一个就直接显示(),
    //如果有多个相同,在比较单词长度.
    //如果前面2个都相同,则按照字典升序(sort 即可)
    vector<string> words;
    map<string,int> tempMap;

    set<int,std::greater<int>> wordsLenVec;
    for(auto iter = mapWords.begin();iter != mapWords.end(); ++iter){
        wordsLenVec.emplace(iter->second);
    }

    for(auto iterLen = wordsLenVec.begin(); iterLen != wordsLenVec.end(); ++iterLen){
        tempMap.clear();
        for(auto iter = mapWords.begin(); iter != mapWords.end(); ++iter){
            if(iter->second == *iterLen){
                tempMap[iter->first] = iter->second;
            }
        }
        int tempMapSize = tempMap.size();
        //剩余的word仅有一个最大次数的word,其余word都比该word出现的次数少
        if(tempMapSize == 1){ //
            words.emplace_back(tempMap.begin()->first);
        }else{ //
            vector<string> tempWords;
            for(auto iterMap = tempMap.begin(); iterMap != tempMap.end(); ++iterMap){
                tempWords.emplace_back(iterMap->first);
            }
            sort(tempWords.begin(),tempWords.end(),compareStringLengthAndalphabetical);
            for(auto word: tempWords){
                words.emplace_back(word);
            }
        }
    }
    for(auto word:words){
        int count = mapWords[word];
        for(int i = 0; i < count; ++i){
            std::cout << word << " ";
        }
    }
    std::cout << std::endl;
}
