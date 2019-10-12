/*
给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

你的目标是使用最少的跳跃次数到达数组的最后一个位置。

示例:

输入: [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
说明:

假设你总是可以到达数组的最后一个位置。
*/

/*
解法一：16ms（58%）
贪心：只记录在跳n次下能够达到的最远位置
可优化方向：dp数组可以省略
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int size = nums.size();
        vector<int> dp (size);
        dp[0] = 0;
        int end = nums[0];
        int step = 1;
        while(end<size-1){
            dp[step] = end;
            for(int i=dp[step-1]+1;i<=dp[step];i++){
                end = max(end,i+nums[i]);
            }
            step++;
        }
        return step;
    }
};