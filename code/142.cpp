/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**
 * 同141.cpp
 * /
class Solution {
public:
    ListNode* detectCycle(ListNode *head) {
        unordered_set<ListNode*> s;
        if(head == NULL) return NULL;
        ListNode* end = head;
        s.insert(end);
        end = end->next;
        while(end!=NULL){
            if(s.count(end)>0){
                return end;
            }
            s.insert(end);
            end = end->next;
        }
        return NULL;
    }
};