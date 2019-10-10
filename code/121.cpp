/*
给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。

注意你不能在买入股票前卖出股票。

示例 1:

输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
示例 2:

输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
*/

/*
注意事项：只能买卖一次股票
*/

/*
解法一：12ms（57%）
动态规划
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int days = prices.size();
        vector<int> profit;
        profit.resize(days);
        if(days==0) return 0;
        profit[0] = 0;
        int min = prices[0],max = prices[0];
        int maxPro = 0;
        for(int i=1;i<days;i++){
            if(prices[i]>max){
                max = prices[i];
                profit[i] = max-min>profit[i-1] ? max-min : profit[i-1];
            }
            else if(prices[i]<min){
                min = prices[i];
                max = min;
                profit[i] = profit[i-1];
            }
            else{
                profit[i] = profit[i-1];
            }
            
        }
        return profit[days-1];
    }
};

/*
解法二：
相邻两天股票价格求差，问题转化为求最大连续子数组的和的问题
dp[i] = max(0,dp[i-1]+diff[i])
*/
int maxProfit(vector<int>& prices) {
    if (prices.size() <= 1) return 0;
    vector<int> diff(prices.size() - 1);
    for (int i = 0; i < prices.size() - 1; ++i) {
        diff[i] = prices[i+1] - prices[i];
    }
    
    vector<int> dp(diff.size());
    dp[0] = max(0, diff[0]);
    int profit = dp[0];
    for (int i = 1; i < diff.size(); ++i) {
        dp[i] = max(0, dp[i-1] + diff[i]);
        profit = max(profit, dp[i]);
    }
    return profit;
}