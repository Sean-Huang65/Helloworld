/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**
 * 考察一些链表的基本操作
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next == nullptr || k==0) return head;
        int cnt=0;
        ListNode* end=head;
        while(end!=nullptr){
            end=end->next;
            cnt++;
        }
        k = (cnt-(k%cnt))%cnt;
        if(k==0){
            return head;
        }
        ListNode*prev = NULL;
        ListNode* curr = head;
        for(int i=0; i<k; i++){
            prev = curr;
            curr = curr->next;
        }
        end = curr;
        while(end->next!=NULL){
            end = end->next;
        }
        end->next = head;
        prev->next = NULL;
        return curr;
    }
};