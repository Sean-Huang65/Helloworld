/**
 * 时间：61%
 * 直接找规律遍历解决
 * 注意一下输入k=0的边界情况
 */
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int size = nums.size();
        if(size<2) return false;
        for(int i=1;i<size;i++){
            int sum = nums[i];
            for(int j=i-1;j>=0;j--){
                sum+=nums[j];
                if((k==0 && sum==0) || (k!=0 && sum % k==0)){
                    return true;
                }
            }
        }
        return false;
    }
};

/***
 * 方法二：hash
 * 记录下前n个数的总和，如果mod k出现两次相同值则说明中间部分数组满足条件
 */
