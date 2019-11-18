/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**
 * 解法一：
 * 遍历所有链表，内置sort()函数排序，遍历生成
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* p;
        vector<int> nums;
        for(int i=0; i<lists.size(); i++){
            p = lists[i];
            while(p!=NULL){
                nums.push_back(p->val);
                p = p->next;
            }
        }
        sort(nums.begin(),nums.end());
        ListNode* res=NULL;
        ListNode* end=NULL;
        if(nums.size() == 0) return res;
        res = new ListNode(nums[0]);
        end = res;
        for(int i=1; i<nums.size(); i++){
            end->next = new ListNode(nums[i]);
            end = end->next;
        }
        return res;
    }
};