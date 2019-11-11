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