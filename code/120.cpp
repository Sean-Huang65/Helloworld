/*
给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。

例如，给定三角形：

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。

说明：

如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。
*/

/*
解法一：8ms(77%)
动态规划
*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int h = triangle.size();
        vector<vector<int>> dp(h,vector<int>(h));
        dp[0][0] = triangle[0][0];
        if(h<=1) return dp[0][0];
        for(int i=1;i<triangle.size(); i++){
            for(int j=0;j<=i;j++){
                if(j==0){
                    dp[i][j] = dp[i-1][j] + triangle[i][j];
                }
                else if(j==i){
                    dp[i][j] = dp[i-1][j-1] + triangle[i][j];
                }
                else{
                    dp[i][j] = min(dp[i-1][j-1],dp[i-1][j]) + triangle[i][j];
                }
            }
        }
        int res = INT_MAX;
        for(int i=0;i<h;i++){
            res = min(dp[h-1][i],res);
        }
        return res;
    }
};