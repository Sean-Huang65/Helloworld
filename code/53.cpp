/*
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。

*/

/*
解法一：4ms（99%）
动态规划 
dp[i] = max(0,dp[i-1]) + nums[i];
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size);
        if(size<=1) return nums[0];
        dp[0] = nums[0];
        int m = dp[0];
        for(int i=1;i<size;i++){
            dp[i] = max(dp[i-1], 0) + nums[i];
            m = max(dp[i],m);
        }
        return m;
    }
};