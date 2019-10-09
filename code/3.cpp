#include <iostream>;
#include <map>;
#include <unordered_set>;
using namespace std;

/*
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
*/ 

/*
解法一：24ms
哈希表记录每个字符位置，双指针
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> m;
        int max = 0;
        int i=0,j=0;
        if(s.size()==0) return max;
        max = -1;
        while(j<s.size()){
            if(m.find(s[j])==m.end() || m[s[j]]<i){
                m[s[j]]=j;
                if(j-i+1>max) max = j-i+1;
            }
            else{
                i = m[s[j]]+1;
                m[s[j]] = j;
            }
            j++;
        }
        return max;
    }
};

/*
解法二：
滑动窗口，重复移除最左侧的元素直到序列为无重复子串
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        unordered_set<char> lookup;
        int maxStr = 0;
        int left = 0;
        for(int i = 0; i < s.size(); i++){
            while (lookup.find(s[i]) != lookup.end()){
                lookup.erase(s[left]);
                left ++;
            }
            maxStr = max(maxStr,i-left+1);
            lookup.insert(s[i]);
    }
        return maxStr;
        
    }
};