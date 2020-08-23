/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        // 扱いやすくするためにdummy nodeを用意する
        ListNode *dummy_head = new ListNode(0);
        
        ListNode *p = l1, *q = l2;
        ListNode *cur = dummy_head;
        
        int carry = 0;
        int x, y;
        
        while (p != nullptr || q != nullptr){
            if (p != nullptr){
                x = p->val;
            }
            else x = 0;
            
            if (q != nullptr){
                y = q-> val;
            }
            else y = 0;
            
            int sum = carry + x + y;
            carry = sum / 10;
            
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            
            if (p != nullptr) p = p->next;
            if (q != nullptr) q = q->next;
        }
        if (carry > 0) cur->next = new ListNode(carry);
        
        return dummy_head->next;
    }
};
