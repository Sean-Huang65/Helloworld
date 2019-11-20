/**
 * //解法一：哈希映射
 * 哈希映射存储数组数值->index的映射
 * 遍历数组，如果差值在哈希映射中存在，则返回，不存在则将新映射存入映射集合
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        vector<int> res;
        for(int i=0; i<nums.size(); i++){
            if(m.find(target-nums[i])!=m.end()){
                res.push_back(m[target-nums[i]]);
                res.push_back(i);
                return res;
            }
            m[nums[i]] = i;
        }
        return res;
    }
};