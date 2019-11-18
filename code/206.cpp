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
 * 遍历一次，数据入栈，着实愚蠢
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        stack<int> s;
        if(head == nullptr) return nullptr;
        ListNode* tmp = head;
        ListNode* res;
        while(tmp!=nullptr){
            s.push(tmp->val);
            tmp = tmp->next;
        }
        res = new ListNode(s.top());
        ListNode* end = res;
        s.pop();
        while(!s.empty()){
            ListNode* node = new ListNode(s.top());
            end->next = node;
            end = end->next;
            s.pop();
        }
        return res;
    }
};

/**
 * 解法二：
 * 原地反转
 * 重要！！！
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while(curr!=nullptr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};