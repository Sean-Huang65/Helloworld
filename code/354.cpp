/*
给定一些标记了宽度和高度的信封，宽度和高度以整数对形式 (w, h) 出现。当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。

请计算最多能有多少个信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。

说明:
不允许旋转信封。

示例:

输入: envelopes = [[5,4],[6,4],[6,7],[2,3]]
输出: 3 
解释: 最多信封的个数为 3, 组合为: [2,3] => [5,4] => [6,7]。
*/

/*
解法一：（超时）
*/

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int num = envelopes.size();
        if(num<=1) return num;
        for(int i=0;i<num;i++){
            for(int j=0;j<num-i-1;j++){
                if(envelopes[j][0]>envelopes[j+1][0] || 
                   (envelopes[j][0]==envelopes[j+1][0] && envelopes[j][1]>envelopes[j+1][1])){
                    vector<int> temp;
                    temp = envelopes[j+1];
                    envelopes[j+1] = envelopes[j];
                    envelopes[j] = temp;
                }
            }
        }
        int maxh = 0,maxw = 0;
        vector<int> res(num);
        res[0] = 1;
        for(int i=1;i<num;i++){
            int maxn = 1;
            for(int j=i-1;j>=0;j--){
                if(envelopes[i][1]>envelopes[j][1]){
                    if(envelopes[i][0] == envelopes[j][0] && maxn < res[j]){
                        maxn = res[j];
                    }
                    else if(envelopes[i][0] > envelopes[j][0] && maxn < res[j]+1){
                        maxn = res[j]+1;
                    }
                }
            }
            res[i] = maxn;
        }
        int r = 0;
        for(int i=0;i<num;i++){
            r = max(r,res[i]);
        }
        return r;
    }
};