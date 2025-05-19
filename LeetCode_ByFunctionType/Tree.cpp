#include <gtest/gtest.h>
#include <vector>
#include <stack>
#include <queue>
#include <stringUtil.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void traversal(TreeNode *node, vector<int> &vec){
    if(node ==  nullptr) return;
    vec.push_back(node->val);
    traversal(node->left,vec);
    traversal(node->right,vec);
}

//144. 二叉树的前序遍历
//输入：root = [1,2,3,4,5,null,8,null,null,6,7,9]
//输出：[1,2,4,5,6,7,3,8,9]
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> vec;
    if(root == nullptr) return vec;
    traversal(root,vec);
    return vec;
}

//二叉树的前序遍历(stack)
vector<int> proorderTraversalWithStack(TreeNode *root)
{
    vector<int> vec;
    stack<TreeNode *> stack;
    if(root == nullptr)
        return vec;
    TreeNode *node = root;
    stack.push(root);
    while(!stack.empty()){
        node = stack.top();
        stack.pop();
        if(node == nullptr) continue;
        vec.emplace_back(node->val);
        if(node->right){
            stack.push(node->right);
        }
        if(node->left){
            stack.push(node->left);
        }
    }
    return vec;
}

//二叉树的后序遍历(stack)
vector<int> postorderTraversalWithStack(TreeNode* root) {
    vector<int> vec;
    stack<TreeNode *> stack;
    if(root == nullptr)
        return vec;
    TreeNode *node = root;
    stack.push(root);
    while(!stack.empty()){
        node = stack.top();
        stack.pop();
        if(node == nullptr) continue;
        vec.emplace_back(node->val);
        if(node->left){
            stack.push(node->left);
        }
        if(node->right){
            stack.push(node->right);
        }
    }
    std::reverse(vec.begin(),vec.end()); //
    return vec;
}

//二叉树的中序遍历(stack)
vector<int> inorderTraversalWithStack(TreeNode* root)
{
    vector<int> result;
    stack<TreeNode*> st;
    TreeNode* cur = root;
    while (cur != NULL || !st.empty()) {
        if (cur != NULL) { // 指针来访问节点，访问到最底层
            st.push(cur); // 将访问的节点放进栈
            cur = cur->left;                // 左
        } else {
            cur = st.top(); // 从栈里弹出的数据，就是要处理的数据（放进result数组里的数据）
            st.pop();
            result.push_back(cur->val);     // 中
            cur = cur->right;               // 右
        }
    }
    return result;

}

#include <cmath>

//LeetCode 102. 二叉树的层序遍历
//给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。
vector<vector<int>> levelOrder(TreeNode* root)
{
    std::queue<TreeNode *> que;
    vector<vector<int>> result;
    if(root == nullptr)
        return result;
    TreeNode* node = root;
    que.push(root);
    int size = 1;
    vector<int> res;
    while(!que.empty()){
       size = que.size();
       for(int i = 0; i < size; ++i){
           node = que.front();
           que.pop();
           res.emplace_back(node->val);
           if(node->left){
              que.push(node->left);
           }
           if(node->right){
               que.push(node->right);
           }
       }
       result.emplace_back(res);
       res.clear();
    }
    return  result;
}

//LeetCOde226 给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。

//示例 1：
//输入：root = [4,2,7,1,3,6,9]
//输出：[4,7,2,9,6,3,1]
void invert(TreeNode *node)
{
    if(node == nullptr || (node->left == nullptr && node->right == nullptr))
        return;
    TreeNode *temp = node->left;
    node->left = node->right;
    node->right = temp;
    invert(node->left);
    invert(node->right);
}

bool compare(TreeNode *left, TreeNode *right)
{
    //
    if(left  == nullptr && right != nullptr) return false;
    if(right == nullptr && left != nullptr) return false;
    if(right == nullptr &&  left == nullptr) return true;
    if(right->val != left->val) return false;
    //比较外侧
    bool outside = compare(left->left,right->right);//
    //比较内侧
    bool inside = compare(left->right,right->left);//
    return outside && inside;
}

//LeetCode 101. 对称二叉树
//给你一个二叉树的根节点 root ， 检查它是否轴对称。
bool isSymmetric(TreeNode* root)
{
    //使用层序遍历,然后判断2边的节点是否对称,非递归(迭代的方式)
//    if(root == nullptr || (root->right == nullptr && root->left == nullptr))
//        return true;
//    int size = 0;
//    queue<TreeNode *> que;
//    que.push(root);
//    while(!que.empty()){
//       int tempSize =  size = que.size();
//        vector<int> vec;
//        while(size--){
//            TreeNode *node = que.front();
//            que.pop();
//            if(node != nullptr){
//              vec.emplace_back(node->val);
//            }else{
//                vec.emplace_back(-101);
//            }
//            if(node){
//                que.push(node->right);
//                que.push(node->left);
//            }
//        }

//        for(int i = 0; i < tempSize / 2; ++i){
//            int j = tempSize - i - 1;
//            if(vec[i] != vec[j])
//                return false;
//        }
//        vec.clear();
//    }
//    return true;

    if(root == nullptr || (root->right == nullptr && root->left == nullptr))
        return true;
    bool flag = compare(root->left,root->right);
    return flag;
}

//LeetCode 104. 给定一个二叉树 root ，返回其最大深度。
//二叉树的 最大深度 是指从根节点到最远叶子节点的最长路径上的节点数。

//高度: 叶子节点到根节点的最大深度 -->使用后序遍历(即先求出左孩子,然后右孩子,最后求自身)
//深度:任意节点到根节点的距离(根节点到自身的距离为1) --> -->使用前序遍历
//最大深度-->其实就是求高度.
int maxDepth(TreeNode* root)
{
    if(root == nullptr) return 0;
    if(root->left == nullptr && root->right == nullptr) return 1;
    int leftLength = maxDepth(root->left);
    int rightLength = maxDepth(root->right);
    return max(leftLength,rightLength) + 1;
}


int minte(TreeNode *node)
{

}

//LeetCode 111. 二叉树的最小深度
//使用前序遍历

#include <climits>
int minDepth(TreeNode* root)
{
   if(root == nullptr) return 0;
   if(root->left == nullptr && root->right == nullptr) return 1;
   int leftLength = minDepth(root->left);
   int rightLength = minDepth(root->right);
   if(leftLength  == 0)
       leftLength = INT_MAX - 1;
   if(rightLength == 0)
       rightLength = INT_MAX  - 1;
   return min(leftLength,rightLength) + 1;
}

int countNodes(TreeNode* root) {
    
    //
    if(root == nullptr) return 0;
    queue<TreeNode *>que;
    que.push(root);
    int size = 0;
    TreeNode *cur;
    while(!que.empty()){
        cur = que.front();
        que.pop();
        ++size;
        if(cur->left)
            que.push(cur->left);
        if(cur->right)
            que.push(cur->right);
    }
    return size;

}

TEST(LeetCode, Tree)
{
    TreeNode  *root = new TreeNode(1);
    TreeNode *node1 = new TreeNode(2);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
//    TreeNode *node4 = new TreeNode(4);
//    TreeNode *node5 = new TreeNode(4);
    TreeNode *node6 = new TreeNode(3);
    root->left = node1;
    root->right = node2;
    node1->right = node3;
    node2->right = node6;
//    node2->left = node5;
//    node2->right = node6;
    countNodes(root);
   // isSymmetric(root);
    //levelOrder(root);
//    preorderTraversal(root);
//    proorderTraversalWithStack(root);
//    postorderTraversalWithStack(root);
//    inorderTraversalWithStack(root);
}
