/************
 * 编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target。该矩阵具有以下特性：

每行的元素从左到右升序排列。
每列的元素从上到下升序排列。
示例:

现有矩阵 matrix 如下：

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
给定 target = 5，返回 true。

给定 target = 20，返回 false。

*/

/**
 * 注意事项：
 * 二维数组问题，数组为空的情况可能是行为0（[]），也可能是列为0（[[]]）
 */

/*
解法一:80ms(80%)
时间复杂度O(m+n)
通过不断修剪，最终找到目标元素
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        if(r==0) return false;
        int c = matrix[0].size();
        if(c==0) return false;
        int j=c-1,i=0;
        while(j>=0 && i<r){
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j]<target){
                i++;
            }
            else{
                j--;
            }
        }
        return false;
    }
};