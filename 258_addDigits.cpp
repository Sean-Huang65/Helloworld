class Solution {
public:
    //循环实现
    int addDigits(int num) {
        int output;
        while (num >= 10){
            output = 0;
            while (num != 0){
                output += (num%10);
                num /= 10;
            }
            num = output;
        }
        return num;
    }

    //递归实现
    int addDigits(int num) {
        if(num < 10){
            return num;
        }
        int result = 0;
        while(num!=0){
            result += num%10;
            num/=10;
        }
        return addDigits(result);
    }

    //O(1) 实现
    int addDigits(int num) {
        return (num-1)%9+1;
    }
};

int main(int argc, char const *argv[])
{
    int num=0;
    Solution r;
    int result = r.addDigits(num);
    return 0;
}
