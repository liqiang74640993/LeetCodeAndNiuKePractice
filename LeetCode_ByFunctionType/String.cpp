#include <gtest/gtest.h>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

//LeetCode 344 反转字符串
//编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。
//不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
void reverseString(vector<char>& s)
{
    int size = s.size();
    int i = 0, j = 0;
    for(i = 0, j = size - 1; i < size / 2; ++i,--j){
        swap(s[i],s[j]);
    }
}

//给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。
//- 如果剩余字符少于 k 个，则将剩余字符全部反转。
//- 如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
//示例 1：
//输入：s = "abcdefg", k = 2
//输出："bacdfeg"
//示例 2：
//输入：s = "abcd", k = 2
//输出："bacd"
string reverseStr(string s, int k)
{
    int size = s.size();
//    if(size == 0) return s;
//    int allCount = size / (2 * k); //
//    if(size % (2*k) != 0){
//        allCount++;
//     }

//    int count = 0;
//    while(count < allCount){
//       int index = count * 2 * k;
//       if(size < k){
//           k = size;
//       }
//       int i = 0, j = 0;
//       for(i = index, j = index +  k - 1; i <= index + (k - 1)/2 ; ++i,--j){
//           swap(s[i],s[j]);
//       }
//       size = size - 2 * k;
//       ++count;
//    }
//   return s;

   for(int i = 0; i < size; i += 2 * k){
        int start = i;
        int elements  = size -  start;
        if(elements < k){
            k = elements;
        }
       int m = 0, n = 0;
       for(m = start, n = start +  k - 1; m <= start + (k - 1)/2 ; ++m,--n){
           swap(s[m],s[n]);
       }
   }
    return s;
}


string reverseWords(string s)
{
    int size = s.size();
    vector<string> vec;
    int start = 0, wordLen = 0;
    for(int i = size - 1; i > 0; i--){
        if(std::isspace(s[i])){
            continue;
        }
        start = i;
        int j;
        for(j = start; j > 0; --j){
           if(std::isspace(s[j])){
               break;
           }
        }
        wordLen = start  - j;
        string temp = s.substr(j+1,wordLen);
        vec.emplace_back(s.substr(j,wordLen));

        i += wordLen;

        std::cout << "wordLen:" << wordLen << std::endl;
    }
    size = vec.size();
    s.clear();
    for(int i = size - 1; i > 0; i--){
        s.append(vec[i].begin(),vec[i].end());
        s.append(" ");
    }
    s.append(vec[0].begin(), vec[0].end());
    return s;


//    int size = s.size();
//    vector<string> vec;
//    int start = 0, wordLen = 0;
//    for(int i = 0; i < size; i++){
//        if(std::isspace(s[i])){
//            continue;
//        }
//        start = i;
//        int j;
//        for(j = start + 1; j < size; ++j){
//           if(std::isspace(s[j])){
//               break;
//           }
//        }
//        wordLen = j  - start;
//        vec.emplace_back(s.substr(start,wordLen));

//        i += wordLen;

//        std::cout << "wordLen:" << wordLen << std::endl;
//    }
//    size = vec.size();
//    s.clear();
//    for(int i = size - 1; i > 0; i--){
//        s.append(vec[i].begin(),vec[i].end());
//        s.append(" ");
//    }
//    s.append(vec[0].begin(), vec[0].end());
//    return s;
}

TEST(LeetCode, String)
{
    vector<char> s;
    reverseWords("  hello world  ");
}
