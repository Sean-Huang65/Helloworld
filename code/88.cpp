/**
 * 给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。

说明:

初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
示例:

输入:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

输出: [1,2,2,3,5,6]

*/

/**
 * 注意事项：
 * 两数组合并长度有可能比原nums1预设长度短，合并结束后nums1结尾可能还有0；
 */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums3 (max(m+n,int(nums1.size())),0);
        int id1 = 0;
        int id2 = 0;
        int id3 = 0;
        while(id1<m && id2<n){
            if(nums1[id1]<nums2[id2]){
                nums3[id3]=nums1[id1];
                id1++;
            }
            else{
                nums3[id3]=nums2[id2];
                id2++;
            }
            id3++;
        }
        while(id1<m){
            nums3[id3++] = nums1[id1++]; 
        }
        while(id2<n){
            nums3[id3++] = nums2[id2++];
        }
        nums1 = nums3;
    }
};