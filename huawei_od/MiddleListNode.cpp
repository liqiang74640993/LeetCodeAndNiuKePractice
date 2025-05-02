//寻找链表的中间结点
//题目描述
//给定一个单链表 L，请编写程序输出 L
//中间结点保存的数据。如果有两个中间结点，则输出第二个中间结点保存的数据。
//例如：给定 L 为 1→7→5，则输出应该为 7；给定 L 为 1→2→3→4，则输出应该为 3。
//输入描述
//每个输入包含 1 个测试用例。每个测试用例第 1
//行给出链表首结点的地址、结点总个数正整数 N (≤105)。结点的地址是 5
//位非负整数，NULL 地址用
//−1 表示。
//接下来有 N 行，每行格式为：
//Address Data Next
//其中 Address 是结点地址，Data 是该结点保存的整数数据(0 ≤ Data ≤ 108)，Next
//是下一结点的地址。输出描述
//对每个测试用例，在一行中输出 L
//中间结点保存的数据。如果有两个中间结点，则输出第二个中间结点保存的数据。

#include <gtest/gtest.h>
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

struct Node{
  int cur;
  int val;
  int next;
};

TEST(HuaWeiOd, MiddleListNode)
{
    int n;
    string head;
    std::cin >> head >> n;

    //key:节点地址
    //value:val and 下一个节点地址
    string address,next;
    int val;

    //input all nodes
    std::unordered_map<string,pair<int,string>> nodeListMap;
    for(int i = 0; i < n; ++i){
        cin >> address >> val >> next;
        nodeListMap.insert(pair(address,pair(val,next)));
    }

    auto headNode = nodeListMap.find(head);
    if(headNode == nodeListMap.end()) //head is not exist
        return;
    std::map<int, int> keyMap;
    auto node = headNode;
    int index = 0;
    string tempAddress = node->second.second;
    auto pair = node->second;
    while(tempAddress != "-1"){
       keyMap[index++] = pair.first;
       pair = nodeListMap[pair.second];
       tempAddress = pair.second;
    }
    keyMap[index] = pair.first;// 最后一个元素的val
    if(index % 2 == 0)
       index = index / 2;
    else
       index = index / 2 + 1;
    std::cout << keyMap[index] << std::endl;


//    //int n;
//    //第二种方式:快慢指针
//    string headAddress;
//    cin >> headAddress >> n;

//    // 使用unordered_map存储每个节点的值和下一个节点的地址
//    unordered_map<string, pair<string, string>> nodeMap;
//    for (int i = 0; i < n; i++) {
//        string address, value, nextAddress;
//        cin >> address >> value >> nextAddress;
//        nodeMap[address] = {value, nextAddress}; // 将数据存入哈希表
//    }

//    // 如果头节点不存在，直接退出
//    if (nodeMap.find(headAddress) == nodeMap.end()) {
//        return;
//    }

//    // 初始化慢指针和快指针，均指向头节点
//    string slow = headAddress, fast = headAddress;

//    // 快指针每次走两步，慢指针每次走一步，直到快指针到达链表末尾
//    while (fast != "-1" && nodeMap.find(fast) != nodeMap.end()) {
//        fast = nodeMap[fast].second; // 快指针走一步
//        if (fast == "-1" || nodeMap.find(fast) == nodeMap.end()) {
//            break; // 快指针到达链表末尾，退出循环
//        }
//        fast = nodeMap[fast].second; // 快指针再走一步
//        slow = nodeMap[slow].second; // 慢指针走一步
//    }

//    // 输出慢指针指向的节点的值
//    cout << nodeMap[slow].first << endl;
}
