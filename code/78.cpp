/**
 * 解法一：
 * dp题
 * 遍历数组，将结果数组中之前的每个元素末尾添加上当前的遍历到的数值，添加在结果数组的最后
 */

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int nums_size = nums.size();
        vector<vector<int>> res;
        res.push_back(vector<int> {});
        for(int i=0; i<nums_size; i++){
            int tmp_size = res.size();
            for(int j=0; j<tmp_size; j++){
                vector<int> next = res[j];
                next.push_back(nums[i]);
                res.push_back(next);
            }
        }
        return res;
    }
};