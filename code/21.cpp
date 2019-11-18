/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* res, *end;
        if(l1==nullptr) return l2;
        if(l2==nullptr) return l1;
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        if(l1->val < l2->val){
            res = new ListNode(l1->val);
            curr1 = curr1->next;
        }
        else{
            res = new ListNode(l2->val);
            curr2 = curr2->next;
        }
        end = res;
        while(curr1!=nullptr && curr2!=nullptr){
            if(curr1->val < curr2->val){
                end->next = new ListNode(curr1->val);
                curr1 = curr1->next;
                end = end->next;
            }
            else{
                end->next = new ListNode(curr2->val);
                curr2 = curr2->next;
                end = end->next;
            }
        }
        if(curr1 == nullptr){
            end->next = curr2;
        }
        else if(curr2 == nullptr){
            end->next = curr1;
        }
        return res;
    }
};