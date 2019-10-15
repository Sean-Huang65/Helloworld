/**
 * 编写一个程序，找出第 n 个丑数。

丑数就是只包含质因数 2, 3, 5 的正整数。

示例:

输入: n = 10
输出: 12
解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
说明:  

1 是丑数。
n 不超过1690。
*/

/**
 * 解法一：12ms（74%）
 * 动态规划
 * 最优子结构：
 * 新的丑数是之前的某个数*2/3/5得到，只需用三个指针分别从丑数数组最左端开始遍历
 * 三个指针分别代表*2/3/5，选取其中最小者作为新的丑数即可
 * ！注意：会出现多个指针对应数增长之后相等的情况，需要同时将多个指针右移
 */
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res(1690,0);
        res[0] = 1;
        int id2 = 0;
        int id3 = 0;
        int id5 = 0;
        for(int i=1;i<n;i++){
            res[i] = min(min(res[id2]*2,res[id3]*3),res[id5]*5);
            if(res[i]==res[id2]*2) id2++;
            if(res[i]==res[id3]*3) id3++;
            if(res[i]==res[id5]*5) id5++;
        }
        return res[n-1];
    }
};