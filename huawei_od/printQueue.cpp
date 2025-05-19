
//华为OD机试 - 打印机队列（Java & JS & Python）
//题目描述

//有5台打印机打印文件，每台打印机有自己的待打印队列。

//因为打印的文件内容有轻重缓急之分，所以队列中的文件有1~10不同的代先级，其中数字越大优先级越高。

//打印机会从自己的待打印队列中选择优先级最高的文件来打印。

//如果存在两个优先级一样的文件，则选择最早进入队列的那个文件。

//现在请你来模拟这5台打印机的打印过程。

//输入描述

//每个输入包含1个测试用例，

//每个测试用例第一行给出发生事件的数量N（0 < N < 1000）。

//接下来有 N 行，分别表示发生的事件。共有如下两种事件：

//    “IN P NUM”，表示有一个拥有优先级 NUM 的文件放到了打印机 P 的待打印队列中。（0< P <= 5, 0 < NUM <= 10)；
//    “OUT P”，表示打印机 P 进行了一次文件打印，同时该文件从待打印队列中取出。（0 < P <= 5）。

//输出描述

//    对于每个测试用例，每次”OUT P”事件，请在一行中输出文件的编号。
//    如果此时没有文件可以打印，请输出”NULL“。
//    文件的编号定义为”IN P NUM”事件发生第 x 次，此处待打印文件的编号为x。编号从1开始。

#include <gtest/gtest.h>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Task{
    int tasknum;
    int pri;
    Task():tasknum(0),pri(0){}
    Task(int _tasknum,int _pri):tasknum(_tasknum),
        pri(_pri){}
};

struct compare{
    bool operator()(const Task &task1, const Task &task2){
        if(task1.pri == task2.pri){
            return task1.tasknum > task2.tasknum;
        }
        return task1.pri < task2.pri;
    }
};

typedef priority_queue<Task,vector<Task>, compare> TaskQue;

TEST(HuaWeiOd, printQueue)
{
    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // 清除缓冲区
    vector<string> taskStrVec;
    map<int,TaskQue> map;
    vector<int> output;
    int taskNum = 0;
    for(int i = 0; i < N; ++i){
        std::string taskStr;
        std::getline(std::cin, taskStr);  // 读取一行到 line
        if(taskStr.substr(0,2) == "IN"){
            int print = std::atoi(taskStr.substr(3,1).c_str());
            int pri = std::atoi(taskStr.substr(5,1).c_str());
            map[print].push(Task(++taskNum,pri));
        }else{//out
            int print = std::atoi(taskStr.substr(4,1).c_str());
            if(map.find(print) == map.cend()){
                output.emplace_back(0);
            }else{
                TaskQue taskQue = map[print];
                Task task = taskQue.top();
                output.emplace_back(task.tasknum);
                taskQue.pop();
                if(taskQue.empty()){
                    map.erase(print);
                }
            }
            ++taskNum;
        }
        taskStrVec.emplace_back(taskStr);
    }
    for(auto i: output){
        if(i == 0){
            std::cout << "NULL" << std::endl;
        }else{
            std::cout << i <<  std::endl;
        }
    }

   // map<int,TaskQue> map;
   // TaskQue que
}
