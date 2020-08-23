/*
  solution1: reverse lists -> add two linked list numbers -> reverse the list -> return the list
*/

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
private:
    ListNode* ReverseLinkedLists(ListNode* l){
        ListNode* prev = nullptr;
        ListNode *cur = l;
        
        while (cur != nullptr){
            ListNode *temp = cur->next;
            
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        return prev;
    }
    
    ListNode *Calc(ListNode* p, ListNode* q){
        ListNode* dummy = new ListNode(0);
        ListNode *cur = dummy;
        
        int x,y;
        int carry = 0;
        
        while (p != nullptr || q != nullptr){
           
            if (p != nullptr){
                x = p->val;
            }
            else x = 0;
            
            if (q != nullptr){
                y = q->val;
            }
            else y = 0;
            
            int temp = carry + x + y;
            
            carry = temp / 10;
            
            cur->next = new ListNode(temp % 10);
            cur = cur->next;
            
            if (p != nullptr) p = p->next;
            if (q != nullptr) q = q->next;
            
        }
        
        if (carry) cur->next = new ListNode(carry);
        return dummy->next;
    }
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *rl1 = ReverseLinkedLists(l1);
        ListNode *rl2 = ReverseLinkedLists(l2);
        
        ListNode *temp = Calc(rl1,rl2);
        
        ListNode *ans = ReverseLinkedLists(temp);
        return ans;
    }
};
