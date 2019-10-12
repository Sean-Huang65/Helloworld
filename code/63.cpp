/*
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？



网格中的障碍物和空位置分别用 1 和 0 来表示。

说明：m 和 n 的值均不超过 100。

示例 1:

输入:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
输出: 2
解释:
3x3 网格的正中间有一个障碍物。
从左上角到右下角一共有 2 条不同的路径：
1. 向右 -> 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右 -> 向右
*/

/*
注意事项：int数值越界！！！int上界 2*10^10
直接用unsigned int上界转为4*10^10
*/

/*
解法一：4ms （90%）
动态规划
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int h = obstacleGrid.size();
        int w = obstacleGrid[0].size();
        vector<vector<unsigned int>> dp(h,vector<unsigned int>(w,0));
        dp[h-1][w-1] = 1;
        for(int i=h-1;i>=0;i--){
            for(int j=w-1; j>=0; j--){
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                }
                else{
                    if(i+1 == h && j+1 < w){
                        dp[i][j] = dp[i][j+1];
                    }
                    else if(i+1 < h && j+1 == w){
                        dp[i][j] = dp[i+1][j];
                    }
                    else if(i+1 < h && j+1 < w){
                        dp[i][j] = dp[i+1][j] + dp[i][j+1];
                    }
                }
            }
        }
        return dp[0][0];
    }
};