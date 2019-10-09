#include <vector>

using namespace std;
class Solution {
public:
    //应用类题
    //对于边界的操作不够熟练
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int result=0;
        for(int i = 0; i<calories.size()-k+1; i++){
            int temp = 0;
            for(int j=0; j<k ;j++){
                temp += calories[i+j];
            }
            if(temp > upper){
                result+=1;
            }
            else if(temp < lower){
                result -= 1;
            }
        }
        return result;
    }
};