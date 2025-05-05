#include <gtest/gtest.h>
#include <vector>
#include <cmath>

using namespace std;

//给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。


//示例 1:

//输入: nums = [-1,0,3,5,9,12], target = 9
//输出: 4
//解释: 9 出现在 nums 中并且下标为 4

//示例 2:

//输入: nums = [-1,0,3,5,9,12], target = 2
//输出: -1
//解释: 2 不存在 nums 中因此返回 -1



//提示：

//    你可以假设 nums 中的所有元素是不重复的。
//    n 将在 [1, 10000]之间。
//    nums 的每个元素都将在 [-9999, 9999]之间。
int binarySearch(vector<int>& nums, int target)
{
    int left = 0, right = nums.size() - 1;
    int middle = (right + left) / 2;
    while(left <= right){ //[]
        if(nums[middle] < target){
            left = middle + 1;
            middle = (right + left) / 2;
        }else if(nums[middle] > target){
            right = middle - 1;
            middle = (right + left) / 2;
        }else {
            return middle;
        }
    }
    return -1;
}


//
int removeElement(vector<int>& nums, int val)
{
   int length = nums.size();
#ifdef BAOLI //暴力解法
    for(int i = 0; i < length; i++){ //
        if(nums[i] == val){
            for(int j = i; j < length - 1; ++j){
                nums[j] = nums[j+1];
            }
            //memcpy(&nums[i],&nums[i+1],(length - (i+1)) * sizeof(int));//lettcode  通不过
            i--; //可能存在连续要删除的元素,使用后面覆盖前面的元素之后,需要再次检测,元素是否想等
            length--;
        }
    }
    return length;
#else //fast and slow pointer
    int fast = 0, slow = 0;
    for(int i = 0; i < length; ++i){
        if(nums[i] != val){
            nums[slow++] = nums[fast++];
        }else{
            fast++;
        }
    }
    return slow;
#endif

}

//LeetCode 977 有序数组的平方
//给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序
//示例 1：
//输入：nums = [-4,-1,0,3,10]
//输出：[0,1,9,16,100]
//解释：平方后，数组变为 [16,1,0,9,100]
//排序后，数组变为 [0,1,9,16,100]
//示例 2：
//输入：nums = [-7,-3,2,3,11]
//输出：[4,9,9,49,121]
vector<int> sortedSquares(vector<int>& nums)
{
   //逆序
//   int length = nums.size();
//   for(int i = 0; i < length; ++i){
//       nums[i] = nums[i] * nums[i];
//   }
//   sort(nums.begin(),nums.end());
//   return nums;

    int length = nums.size();
    vector<int> result(length,0);
    int left = 0,right = length - 1;
    int index = length - 1;
    for(int i = 0; i < length; ++i){
//        if(left == right){ // 最小
//            result[0] = nums[left] * nums[left];
//            break;
//        }
        //将较大值依次放入最后的下标中
        if(std::abs(nums[left]) <= std::abs(nums[right])){
            result[index--] = nums[right] * nums[right];
            right--;
        }else{
            result[index--] = nums[left] * nums[left];;
            left++;
        }
    }
    return result;
}

//59. 螺旋矩阵 II

//给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。

//示例 1：
//输入：n = 3
//输出：[[1,2,3],[8,9,4],[7,6,5]]

//示例 2：
//输入：n = 1
//输出：[[1]]

vector<vector<int>> generateMatrix(int n)
{
    //提前分配二维数组空间,然后对指定下标进行赋值
    vector<vector<int>> result(n, vector<int>(n));
    //定义遍历行和列所需的变量
    int loop = n / 2;//所需要循环的次数,比如n为3,则仅仅需要遍历一次即可,最后中心的点直接赋值即可.

    //默认的最开始遍历从最上面一行开始遍历,即点(0,0),下一次就是(1,1)
    int startx = 0; //遍历的行起始位置,
    int starty = 0;//遍历的列开始位置
    int index = 0;//给遍历的元素的赋值data
    int offset = 1; //
    while(loop--){
        int i = starty;
        int j = startx;
        //从第一行开始往下遍历
        for(;i < n - offset; ++i){
            result[j][i] =  ++index;
        }
        //从最后一列开始向左遍历,
        for(; j < n - offset; ++j){
            result[j][i] = ++index;
        }
        //从最后行开始往上遍历
        for(; i >= offset; --i){
            result[j][i] = ++index;
        }
        //从第一列开始向右遍历
        for(; j >= offset; --j ){
            result[j][i] = ++index;
        }
        ++offset;
        ++starty;
        ++startx;
    }
    if(n % 2){ //奇数行处理中心节点
        result[n/2][n/2] = ++index;
    }
    return result;
}


TEST(LeetCode, Arrary1)
{
    vector<int> vec;

    vec.emplace_back(-7);
    vec.emplace_back(-3);
    vec.emplace_back(2);
    vec.emplace_back(3);
    vec.emplace_back(11);
//    vec.emplace_back(0);
//    vec.emplace_back(4);
//    vec.emplace_back(2);

    //std::cout << removeElement(vec,2) << std::endl;

   // vector<int> v = sortedSquares(vec);

    //std::cout << binarySearch(vec,9) << std::endl;

    generateMatrix(3);
}
