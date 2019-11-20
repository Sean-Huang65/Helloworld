/**
 * 解法一：98%时间 96%空间
 * 从头到位逐渐遍历1-n所有数
 * inc_pos指针记录最前面一位需要增长的数的位置
 * 每次更新增长每一位inc_pos从前往后
 * 更新结束并记录完成后inc_pos从后往前找到下一次需要更新的最前面一位数
 */ 

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> res_i (k,0);
        for(int i=0; i<k; i++){
            res_i[i] = i+1;
        }
        int inc_pos = k-1; //下一次从哪一位开始增长
        res.push_back(res_i);
        if(k<=0 || k>=n) return res;
        while(inc_pos >= 0){
            res_i[inc_pos]++;
            inc_pos++;
            while(inc_pos < k){
                res_i[inc_pos] = res_i[inc_pos-1]+1;
                inc_pos++;
            }
            inc_pos--;
            res.push_back(res_i);
            while(inc_pos>=0 && n - res_i[inc_pos] <= k - inc_pos - 1){
                inc_pos -= 1;
            }
        }
        return res;
    }
};

/**
 * 解法二：
 * 通过hash表实现，O（n）
 * 从左到右遍历，记录下所有遍历数字的总和，如果出现mod k数值相同的情况，且两种情况的index相差大于1，
 * 则说明中间部分mod k=0.
 * 特殊情况：
 * 连续输出先两个0.
 * /
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int size = nums.size();
        if(size<2) return false;
        for(int i=1; i<size; i++){
            if(nums[i]==0 && nums[i-1]==0) return true;
        }
        if(k==0){
            return false;
        }
        map<int,int> m;
        int sum = nums[0] % k;
        m[sum] = 0;
        for(int i=1; i<size; i++){
            if(nums[i]!=0){
                sum += nums[i];
                sum %= k;
                if((m.find(sum)!=m.end() && i - m[sum] > 1) || sum==0){
                    return true;
                }
                m[sum]=i;
            }
            
        }
        return false;
    }
};