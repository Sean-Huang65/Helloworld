/*
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

示例 1:

输入: num1 = "2", num2 = "3"
输出: "6"
示例 2:

输入: num1 = "123", num2 = "456"
输出: "56088"
说明：

num1 和 num2 的长度小于110。
num1 和 num2 只包含数字 0-9。
num1 和 num2 均不以零开头，除非是数字 0 本身。
不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
*/

/*
注意点：记得去除首部的0！！
*/

/*
解法一：164 ms
暴力法，将num1的从末尾开始分别与num2的每一位相乘求和
多位数×多位数-->一位数×多位数 与 求和-->一位数×一位数与求和
*/
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2 == "0") return "0";
        int l1 = num1.size(),l2 = num2.size();
        string s;
        for(int i=l1-1;i>=0;i--){
            string si;
            int carry = 0;
            for(int j=l2-1;j>=0;j--){
                int mul = (num1[i]-'0') * (num2[j]-'0');
                int rmd = mul%10;
                int temp = carry+rmd;
                carry = mul/10;
                if(temp>9){
                    temp-=10;
                    carry+=1;
                } 
                si=char(temp + '0') + si;
            }
            if(carry>0){
                si=char(carry+'0') + si;
            }
            for(int k=l1-1;k>i;k--){
                si+='0';
            }
            int idi = s.size()-1,idj = si.size()-1;
            int carry2 = 0;
            string temps;
            while(idi>=0 && idj>=0){
                int temp2 = (s[idi] - '0') + (si[idj] - '0') + carry2;
                carry2 = temp2/10;
                if(carry2>0){
                    temp2-=10;
                }
                temps=char(temp2+'0') + temps;
                idi--;
                idj--;
            }
            if(idi<0){
                while(idj>=0){
                    int temp2 = (si[idj] - '0') + carry2;
                    carry2 = temp2/10;
                    if(carry2>0){
                        temp2-=10;
                    }
                    temps=char(temp2+'0') + temps;
                    idj--;
                }
            }
            else if(idj<0){
                while(idi>=0){
                    int temp2 = (s[idi] - '0') + carry2;
                    carry2 = temp2/10;
                    if(carry2>0){
                        temp2-=10;
                    }
                    temps=char(temp2+'0') + temps;
                    idi--;
                }
            }
            if(carry2>0) temps='1' + temps;
            s = temps;
        }
        return s;
    }
};

/*
解法二：
考虑到乘法的特点，num1[i] 与 num2[j] 相乘，对应结果的位数为i+j，i+j+1
*/

class Solution {
public:
    string multiply(string num1, string num2) {
        int n1=num1.size();
        int n2=num2.size();
        string res(n1+n2,'0');
        for(int i=n2-1;i>=0;i--){
            for(int j=n1-1;j>=0;j--){
                int temp=(res[i+j+1]-'0')+(num1[j]-'0')*(num2[i]-'0');
                res[i+j+1]=temp%10+'0';//当前位
                res[i+j]+=temp/10; //前一位加上进位，res[i+j]已经初始化为'0'，加上int类型自动转化为char，所以此处不加'0'
            }
        }
        
//去除首位'0'
        for(int i=0;i<n1+n2;i++){
            if(res[i]!='0')
                return res.substr(i);
        }
        return "0";
       
        
    }
};