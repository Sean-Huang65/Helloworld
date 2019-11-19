/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**
 * 考察链表和hash的基本操作/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> s;
        if(head == NULL) return false;
        ListNode* end = head;
        s.insert(end);
        end = end->next;
        while(end!=NULL){
            if(s.count(end)>0){
                return true;
            }
            s.insert(end);
            end = end->next;
        }
        return false;
    }
};