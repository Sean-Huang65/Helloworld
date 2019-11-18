/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**
 * 时间68%
 * 暴力增长
 * 注意两链表均遍历完但是还有carry的情况
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        if(l1 == nullptr) return l2;
        if(l2==nullptr) return l1;
        int carry=0;
        int sum = l1->val + l2->val;
        ListNode* res = new ListNode(sum%10);
        ListNode* end = res;
        carry = sum/10;
        curr1 = curr1->next;
        curr2 = curr2->next;
        while(curr1 != nullptr && curr2 != nullptr){
            sum = curr1->val + curr2->val + carry;
            carry = sum/10;
            sum %= 10;
            ListNode* node = new ListNode(sum);
            end->next = node;
            end = end->next;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        if(curr1==nullptr){
            while(curr2!=nullptr){
                sum = curr2->val+carry;
                carry=sum/10;
                sum%=10;
                ListNode* node = new ListNode(sum);
                end->next = node;
                end = end->next;
                curr2 = curr2->next;
            }
        }
        else if(curr2==nullptr){
            while(curr1!=nullptr){
                sum = curr1->val+carry;
                carry=sum/10;
                sum%=10;
                ListNode* node = new ListNode(sum);
                end->next = node;
                end = end->next;
                curr1 = curr1->next;
            }
        }
        if(carry==1){
            ListNode* node = new ListNode(carry);
            end->next = node;
            end = end->next;
        }
        return res;
    }
};