/**
 * 给定一个整数数组，判断数组中是否有两个不同的索引 i 和 j，使得 nums [i] 和 nums [j] 的差的绝对值最大为 t，并且 i 和 j 之间的差的绝对值最大为 ķ。

示例 1:

输入: nums = [1,2,3,1], k = 3, t = 0
输出: true
示例 2:

输入: nums = [1,0,1,1], k = 1, t = 2
输出: true
示例 3:

输入: nums = [1,5,9,1,5,9], k = 2, t = 3
输出: false
*/

/*
注意事项：注意整型越界问题！！！
int 范围(2^-31~2^31-1)(-2*10^9)
unsigned 范围(0~2^32-1)
*/

/*
解法一：动态规划，超时
*/
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.size()==0) return false;
        unordered_set<unsigned int> s;
        s.insert(nums[0]);
        int l=0,r=1;
        while(r<nums.size()){
            if(r-l>k){
                s.erase(nums[l]);
                l++;
            }
            long top = long(nums[r])+long(t);
            for(int i=nums[r]-t;i<=top;i++){
                if(s.find(i)!=s.end()){
                    return true;
                }
            }
            s.insert(nums[r]);
            r++;
        }
        return false;
    }
};