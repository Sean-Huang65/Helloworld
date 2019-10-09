#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
class Solution {
public:
    //先排序，后取奇数
    //sort(),给出首尾指针
    int arrayPairSum(vector<int>& nums) {
        int result = 0;
        sort(nums.begin(),nums.end());
        for(int i =0;i<nums.size();i+=2)
            result+=nums[i];
        return result;
    }
};