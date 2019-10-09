
/*
 * 给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。

换句话说，第一个字符串的排列之一是第二个字符串的子串。

示例1:

输入: s1 = "ab" s2 = "eidbaooo"
输出: True
解释: s2 包含 s1 的排列之一 ("ba").
 

示例2:

输入: s1= "ab" s2 = "eidboaoo"
输出: False
 

注意：

输入的字符串只包含小写字母
两个字符串的长度都在 [1, 10,000] 之间

 * 
 */

/*
解法一：340ms
根据s1建立哈希表，对s2根据哈希表进行对照比较
不满足条件的话，左指针向右移动使子串重新满足条件
*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()==0) return true;
        if(s1.size()>s2.size()) return false;
        map<char,int> m;
        for(auto c:s1){
            if(m.find(c)!=m.end()){
                m[c]++;
            }
            else m[c]=1;
        }
        for(int i=0;i<=s2.size()-s1.size();i++){
            map<char, int> temp;
            temp = m;
            int j=i;
            while(j<i+s1.size() && temp.find(s2[j])!=temp.end() && temp[s2[j]]>0){
                temp[s2[j]]--;
                j++;
            }
            if(j==i+s1.size()) return true;
            else if(temp.find(s2[j])==temp.end()){
                i=j;
            }
            else{
                while(s2[i]!=s2[j]) i++;
            }
        }
        return false;
    }
};

/*
解法2：
还没看懂
*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        // 输入数据有效性判断
        if(s2.length() < s1.length())
        {
            return false;
        }
        // hash1 记录s1串的各个字符出现的次数
        // hash2 记录s2串中各个字符出现的次数
        int hash1[26] = {0};
        int hash2[26] = {0};
        // init 预处理
        for(int i = 0; i < s1.length(); ++i)
        {
            hash1[s1[i] - 'a']++;
        }
        // l 左指针，cnt 记录窗口中满足条件的元素个数 cnt == plen即可更新答案
        int l = 0, cnt = 0,s1len = s1.length();
        for(int r = 0; r < s2.length(); ++r)
        {
            // 更新新元素在散列表中的数量
            hash2[s2[r] - 'a'] ++;
            // 根据窗口的变更结果来该表条件值
            if(hash2[s2[r] - 'a'] == hash1[s2[r] - 'a'])
            {
                cnt += hash1[s2[r] - 'a'];
            }
            // 如果当前条件不满足，移动左指针直至条件满足为止
            if(r > s1len - 1)
            {
                if(hash2[s2[l] - 'a'] == hash1[s2[l] - 'a'])
                {
                    cnt -=hash2[s2[l] - 'a'];
                }
                hash2[s2[l] - 'a'] --;
                l ++;
            }
            // 更新结果
            if(cnt == s1len)
            {
                return true;
            }
        }
        return false;
    }
};