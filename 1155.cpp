class Solution {
public:
    //递归实现，超时
    int numRollsToTarget(int d, int f, int target) {
        if(f*d < target)
            return 0;
        else if(d*f==target){
            return 1;
        }
        else if(d==1){
            return 1;
        }
        else{
            int result = 0;
            for(int i=1;i<=f;i++){
                result += numRollsToTarget(d-1,f,target-i);
            }
            return (result) % (10^9+7) ;
        }
    }

    //动态规划
    //从1计算出每个target所含有的种类，二维数组
};