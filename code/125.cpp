/**
 * 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:

输入: "A man, a plan, a canal: Panama"
输出: true
示例 2:

输入: "race a car"
输出: false

*/

/**
 * 解法一：16ms（32%）
 */
class Solution {
public:
    bool isPalindrome(string s) {
        int size = s.size();
        if(size<=1) return true;
        int st = 0;
        int end = size-1;
        while(st<end){
            while(!isalnum(s[st]) && st<end) st++;
            while(!isalnum(s[end]) && st<end) end--;
            if(st<end){
                if(tolower(s[st]) == tolower(s[end])){
                    st++;
                    end--;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};