/*
给定两个数组，编写一个函数来计算它们的交集。

示例 1:

输入: nums1 = [1,2,2,1], nums2 = [2,2]
输出: [2,2]
示例 2:

输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出: [4,9]
说明：

输出结果中每个元素出现的次数，应与元素在两个数组中出现的次数一致。
我们可以不考虑输出结果的顺序。
进阶:

如果给定的数组已经排好序呢？你将如何优化你的算法？
如果 nums1 的大小比 nums2 小很多，哪种方法更优？
如果 nums2 的元素存储在磁盘上，磁盘内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？
*/

/*
解法一：8ms 95%
哈希映射
*/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> m;
        int size1 = nums1.size();
        int size2 = nums2.size();
        vector<int> res;
        if(size1 == 0 || size2 == 0){
            return res;
        }
        for(int i=0; i<size1; i++){
            m.find(nums1[i])==m.end() ? m[nums1[i]] = 1 : m[nums1[i]]+=1;
        }
        for(int i=0;i<size2; i++){
            if(m.find(nums2[i])!=m.end() && m[nums2[i]]>0){
                res.push_back(nums2[i]);
                m[nums2[i]]-=1;
            }
        }
        return res;
    }
};