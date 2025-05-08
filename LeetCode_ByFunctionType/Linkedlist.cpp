#include <gtest/gtest.h>
#include <vector>
#include <set>

using namespace std;

struct ListNode
{
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int _x, ListNode *_next) : val(_x), next(_next) {}
};


ListNode *reverse(ListNode *prev, ListNode *cur)
{
    //结束递归的条件
    if(cur == nullptr) return prev;
    ListNode *temp = cur->next;
    cur->next = prev;
    return reverse(cur, temp); //让prev和cur都向后移动一个位置,然后迭代直到节点为空
}

//206. 反转链表
//给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
ListNode* reverseList(ListNode* head)
{
    //递归实现
    return reverse(NULL,head);//
    //双指针写法
//    ListNode *prev = nullptr; //反转后 的最后一个节点的next为NULL
//    ListNode *cur = head;
//    ListNode *temp = nullptr;//保存反转前下一个节点
//    while(cur != nullptr){
//        temp = cur->next;
//        cur->next = prev;
//        prev = cur;
//        cur = temp;
//    }
//    return prev;
}

//LeetCode 203. 移除链表元素
ListNode* removeElements(ListNode* head, int val)
{
    //not use dummy node
#ifdef NOT_USE_DUMMUY_NODE
    if(head == NULL) return NULL;
    while(head != NULL && head->val == val){
        head =  head->next;
    }
    ListNode *cur = head;
    //比较的是cur->next是否和val值想等,cur是prev,上一次已经比较过
    while(cur != nullptr && cur->next != nullptr){
        if(cur->next->val == val){
            cur->next = cur->next->next;
        }else{
            cur = cur->next;//向前进一个位置
        }
    }
#else
    ListNode  *dummyNode = new ListNode(0);
    dummyNode->next = head;
    ListNode *cur = dummyNode;
    while(cur->next){
        if(cur->next->val == val){
            cur->next = cur->next->next;
        }else{
            cur = cur->next;
        }
    }
    head = dummyNode->next;
    delete dummyNode;
#endif
    return head;
}

//24.给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。

//示例 1：

//输入：head = [1,2,3,4]
//输出：[2,1,4,3]

//示例 2：

//输入：head = []
//输出：[]

//示例 3：

//输入：head = [1]
//输出：[1]

ListNode* swapPairs(ListNode* head)
{
    if(head == nullptr || head->next == nullptr)
        return head;
    ListNode *dummyNode = new ListNode(0);
    dummyNode->next = head;
    ListNode *cur = dummyNode;
    //要交换2个节点,必须找到交换节点的前一个节点
    while(cur->next != nullptr && cur->next->next != nullptr){
        ListNode *temp = cur->next;
        ListNode *temp1 = cur->next->next->next;
        cur->next = cur->next->next;
        cur->next->next = temp;
        temp->next = temp1;
        cur = cur->next->next;
    }
    ListNode *temp = dummyNode->next;
    delete dummyNode;
    return temp;
}

//LeetCode：19.删除链表倒数第N个节点
//给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
ListNode* removeNthFromEnd(ListNode* head, int n)
{
        if(n <= 0) return head;
        ListNode *dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode *cur = dummyNode;
        n++;//fast need be 提前走n+1步
        while(n-- && cur != nullptr){
            cur = cur->next;
        }
       //ListNode *fast = cur->next;//for safe ,cur may be nullptr
        ListNode *fast = cur;
        ListNode *slow = dummyNode;
        while(fast != nullptr){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        ListNode *temp = dummyNode->next;
        delete dummyNode->next;
        return temp;


//    if(n <= 0) return head;
//    ListNode *dummyNode = new ListNode(0);
//    dummyNode->next = head;
//    ListNode *cur = dummyNode;
//    while(n--){
//        cur = cur->next;
//    }
//    ListNode *fast = cur->next;
//    ListNode *slow = dummyNode;
//    while(fast != nullptr){
//        fast = fast->next;
//        slow = slow->next;
//    }
//    slow->next = slow->next->next;
//    ListNode *temp = dummyNode->next;
//    delete dummyNode->next;
//    return temp;
}

//LeetCode 707. 设计链表
//你可以选择使用单链表或者双链表，设计并实现自己的链表。
//单链表中的节点应该具备两个属性：val 和 next 。val 是当前节点的值，next 是指向下一个节点的指针/引用。
//如果是双向链表，则还需要属性 prev 以指示链表中的上一个节点。假设链表中的所有节点下标从 0 开始。
//实现 MyLinkedList 类：
//- MyLinkedList() 初始化 MyLinkedList 对象。
//- int get(int index) 获取链表中下标为 index 的节点的值。如果下标无效，则返回 -1 。
//- void addAtHead(int val) 将一个值为 val 的节点插入到链表中第一个元素之前。在插入完成后，新节点会成为链表的第一个节点。
//- void addAtTail(int val) 将一个值为 val 的节点追加到链表中作为链表的最后一个元素。
//- void addAtIndex(int index, int val) 将一个值为 val 的节点插入到链表中下标为 index 的节点之前。如果 index 等于链表的长度，那么该节点会被追加到链表的末尾。如果 index 比长度更大，该节点将 不会插入 到链表中。
//- void deleteAtIndex(int index) 如果下标有效，则删除链表中下标为 index 的节点。
class MyLinkedList {
public:
    MyLinkedList():next(nullptr),val(0),count(0) {

    }

    int get(int index) {
        if(index >= count || index < 0) return -1;
        getDummyNode();
        MyLinkedList *cur = dummyNode->next;//
        while(index--){
            cur = cur->next;
        }
        return cur->val;
    }

    void addAtHead(int val) {
        MyLinkedList *node = new MyLinkedList();
        node->val = val;
        getDummyNode();
        node->next = dummyNode->next;
        dummyNode->next = node;
        count++;
    }

    void addAtTail(int val) {
        MyLinkedList *node = new MyLinkedList();
        node->val = val;
        getDummyNode();
        MyLinkedList *cur = dummyNode;//
        while(cur->next){ //cur->next
            cur = cur->next;
        }
        cur->next = node;
        count++;
    }

    void addAtIndex(int index, int val) {
        if(index < 0 || index > count) return;
         MyLinkedList *node = new MyLinkedList();
         node->val = val;
         getDummyNode();
         MyLinkedList *cur = dummyNode;//
         while(index--){
             cur = cur->next;
         }
        node->next = cur->next;
        cur->next = node;
        count++;
    }

    void deleteAtIndex(int index) {
        if(index < 0 || index > count - 1) return;
        getDummyNode();
        MyLinkedList *cur = dummyNode;//
        while(index--){
            cur = cur->next;
        }
        MyLinkedList *temp = cur->next;
        cur->next = cur->next->next;
        delete temp;
        count--;
    }
    ~MyLinkedList(){

    }
private:
    void getDummyNode(){
        if(dummyNode == nullptr)
            dummyNode = new MyLinkedList();
    }
private:
    MyLinkedList *next;
    int val;
    int count = 0;
    MyLinkedList *dummyNode = nullptr;
};

//给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。
//图示两个链表在节点 c1 开始相交：

//题目数据 保证 整个链式结构中不存在环。
//注意，函数返回结果后，链表必须 保持其原始结构 。
//示例 1：
//输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
//输出：Intersected at '8'
//解释：相交节点的值为 8 （注意，如果两个链表相交则不能为 0）。
//从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。
//在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
#ifdef getIntersectionNode_double_link //双指针做法
    ListNode *p1 = headA;
    ListNode *p2 = headB;
    if(headA == nullptr ||  headB == nullptr) return nullptr;
    while(1){
        if(p1 == p2){
            return p1;
        }
        p1 = p1->next;
        p2 = p2->next;
        //这个要放在p1 == nullptr或者p2 == nullptr判断之前
        if(p1 == nullptr && p2 == nullptr){
            return nullptr;
        }
        if(p1 == nullptr){
            p1 = headB;
        }
        if(p2 == nullptr){
            p2 = headA;
        }

    }
    return nullptr;
#else //use set
    if(headA == nullptr ||  headB == nullptr)
        return nullptr;
    set<ListNode *> nodeSet;
    ListNode *p = headA;
    while(p != nullptr){
        nodeSet.insert(p);
         p = p->next;
    }

    p = headB;
    while(p != nullptr){
        if(nodeSet.find(p) != nodeSet.cend()){
            return p;
        }
         p = p->next;
    }
    return nullptr;
#endif
}

//Leetcode 141 给你一个链表的头节点 head ，判断链表中是否有环。
//如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，
//评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。注意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。
//如果链表中存在环 ，则返回 true 。 否则，返回 false 。

//for example:
//输入：head = [3,2,0,-4], pos = 1
//输出：true
//解释：链表中有一个环，其尾部连接到第二个节点。

bool hasCycle(ListNode *head) {
   //map的做法
//    map<ListNode *, int> addressPosMap;
//    ListNode *cur = head;
//    int pos = 0;
//    while(cur != nullptr){
//        if(addressPosMap.find(cur) != addressPosMap.end()){ //如果找到相同的map
//            return true;
//        }else{ //在map中没有找到对应的节点,则将其放入到map中
//            addressPosMap[cur] = pos++;
//        }
//        cur = cur->next;
//    }
//    return false;

   //双指针的做法
   ListNode *dummy  = new ListNode();
   dummy->next = head;
   ListNode *slow = dummy->next;
   if(slow == nullptr || slow->next == nullptr) return false;
   //2个节点构成环的情况
   if(slow->next->next == slow) return true;
   ListNode *fast = slow->next;
   while(fast != nullptr && fast->next != nullptr){
       if(fast == slow)
           return true;
       slow  = slow->next;
       fast= fast->next->next;
   }
   delete dummy;
   return false;
}

//Leetcode 142 给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
//如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。
//为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
//如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。
//不允许修改 链表。

//输入：head = [3,2,0,-4], pos = 1
//输出：返回索引为 1 的链表节点
//解释：链表中有一个环，其尾部连接到第二个节点。


ListNode *detectCycle(ListNode *head) {
    //使用map的方式,很简单,但是空间是使用o(n),使用一个map来存储
    // map<ListNode *, int> addressPosMap;
    // ListNode *cur = head;
    // int pos = 0;
    // while(cur != nullptr){
    //     if(addressPosMap.find(cur) != addressPosMap.end()){ //如果找到相同的map
    //         return cur;
    //     }else{ //在map中没有找到对应的节点,则将其放入到map中
    //         addressPosMap[cur] = pos++;
    //     }
    //     cur = cur->next;
    // }
    // return nullptr;

    if(head == nullptr || head->next == nullptr)
        return nullptr;
    ListNode *dummy = new ListNode();
    dummy->next = head;
    ListNode *slow = head;
    ListNode *fast = head->next;
    bool flag = false;
    while(fast && fast->next){
        if(fast == slow){
            flag = true;
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    if(flag){
        fast = dummy;
        while(fast != slow){
            slow = slow->next;
            fast = fast->next;
        }
        delete dummy;
        return fast;
    }else{
        delete dummy;
       return nullptr;
    }
}


TEST(LeetCode, LinkedList)
{

    ListNode *head = new ListNode();
    head->val = 3;
    ListNode *node1 = new ListNode();
    head->next = node1;
    node1->val = 2;
    ListNode  *node2 = new  ListNode();
    node1->next = node2;
    node2->val = 0;
    ListNode *node3 = new ListNode();
    node2->next = node3;
    node3->val = -4;
    node3->next = node1;
    detectCycle(head);


//    ListNode *node2 = new ListNode();
//    node2->val = 3;
//    node1->next = node2;
//    ListNode *node3 = new ListNode();
//    node2->next = node3;
//    node3->val = 4;
//    node3->next = nullptr;
//    ListNode *node4 = new ListNode();
//    node3->next = node4;
//    node4->val = 5;
//    node4->next = nullptr;
//    ListNode *node5 = new ListNode();
//    node4->next = node5;
//    node5->val = 6;
//    node5->next = nullptr;

    removeNthFromEnd(head,1);

    head = swapPairs(head);

    //reverseList(head);


    MyLinkedList* obj = new MyLinkedList();
    int param = obj->get(1);
    std::cout << param << std::endl;
    obj->addAtTail(1);
    obj->addAtTail(3);
    param = obj->get(0);
    std::cout << param << std::endl;
    param = obj->get(1);
    std::cout << param << std::endl;
    obj->addAtIndex(1,2);
    param = obj->get(1);
    std::cout << param << std::endl;
    obj->deleteAtIndex(1);
    param = obj->get(1);
    std::cout << param << std::endl;
}

