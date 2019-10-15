/**
 * 给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j 的差的绝对值最大为 k。

示例 1:

输入: nums = [1,2,3,1], k = 3
输出: true
示例 2:

输入: nums = [1,0,1,1], k = 1
输出: true
示例 3:

输入: nums = [1,2,3,1,2,3], k = 2
输出: false
*/

/**
 * 注意事项：nums数组为空的情况！！！
 */

/**
 * 解法一：28ms（94%）
 * 哈希表记录k长度下存在的所有元素，直接查找
 */
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size()==0) return false;
        unordered_set<int> s;
        int l=0,r=1;
        s.insert(nums[l]);
        while(r<nums.size()){
            if(r-l>k){
                s.erase(nums[l]);
                l++;
            }
            if(s.find(nums[r])!=s.end()){
                return true;
            }
            else{
                s.insert(nums[r]);
                r++;
            }
        }
        return false;
    }
};