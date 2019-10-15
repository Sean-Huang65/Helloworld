/*
我们从一块字母板上的位置 (0, 0) 出发，该坐标对应的字符为 board[0][0]。

在本题里，字母板为board = ["abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"].

我们可以按下面的指令规则行动：

如果方格存在，'U' 意味着将我们的位置上移一行；
如果方格存在，'D' 意味着将我们的位置下移一行；
如果方格存在，'L' 意味着将我们的位置左移一列；
如果方格存在，'R' 意味着将我们的位置右移一列；
'!' 会把在我们当前位置 (r, c) 的字符 board[r][c] 添加到答案中。
返回指令序列，用最小的行动次数让答案和目标 target 相同。你可以返回任何达成目标的路径。

 

示例 1：

输入：target = "leet"
输出："DDR!UURRR!!DDD!"
示例 2：

输入：target = "code"
输出："RR!DDRR!UUL!R!"
 

提示：

1 <= target.length <= 100
target 仅含有小写英文字母。
*/
/**
 * 注意事项：
 * 关于‘z’的边界处理，拨号的index应该始终保持在键盘上，而不仅仅是先上下后左右
 * 
 */

/**
 * 解法一：4ms(80%)
 */
class Solution {
public:
    vector<string> board = {"abcde","fghij","klmno","pqrst","uvwxy","z"};
    string alphabetBoardPath(string target) {
        int x = 0, y = 0;
        string res;
        for(auto c:target){
            if(board[x][y] == c){
                res+= '!';
            }
            else{
                pair<int,int> pos = findc(c);
                int ex=pos.first,ey=pos.second;
                int difx = ex-x,dify = ey-y;
                char cx = difx>0 ? 'D' : 'U';
                char cy = dify>0 ? 'R' : 'L';
                int dirx = difx>0 ? 1 : -1;
                int diry = dify>0 ? 1 : -1;
                while(x!=ex && ((x+dirx)<5 || (x+dirx==5 && y==0))){
                    res+=cx;
                    x+=dirx;
                }
                for(int i=0;i<abs(dify);i++){
                    res+=cy;
                    y+=diry;
                }
                if(x!=ex){
                    res+=cx;
                    x+=dirx;
                }
                res+='!';
            }
        }
        return res;
    }
    pair<int,int> findc(char c){
        int i=0,j=4;
        while(board[i][j]!=c && i<5){
            if(board[i][j]>c){
                j--;
            }
            else{
                i++;
            }
        }
        return i==5?make_pair(5,0):make_pair(i,j); 
    };
};
