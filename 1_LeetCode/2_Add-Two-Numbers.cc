

// 2021/01/14
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
        int tmp = l1->val + l2->val;
        l1 = l1->next, l2 = l2->next;
        int res = tmp / 10;
        
        ListNode *ans = new ListNode(tmp % 10);
        ListNode *cur = ans;
        
        
        while (l1 != nullptr && l2 != nullptr){
            tmp = l1->val + l2->val;
            l1 = l1->next, l2 = l2->next;
            tmp += res;
            
            cur->next = new ListNode(tmp % 10);
            res = tmp / 10;
            cur = cur->next;
        }
        
        while (l1 != nullptr){
            tmp = l1->val;
            l1 = l1->next;
            tmp += res;
            
            cur->next = new ListNode(tmp % 10);
            res = tmp / 10;
            cur = cur->next;
        }
        
        while (l2 != nullptr){
            tmp = l2->val;
            l2 = l2->next;
            tmp += res;
            
            cur->next = new ListNode(tmp % 10);
            res = tmp / 10;
            cur = cur->next;
        }
        
        if (res > 0){
            cur->next = new ListNode(res);
            return ans;
        }
        else return ans;
    }
};

// 2021/01/13
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
        int tmp = l1->val + l2->val;
        int res = tmp / 10;
        
        int q = tmp % 10;
        
        ListNode *ans = new ListNode(q);
        ListNode *cur = ans;
        
        l1 = l1->next, l2 = l2->next;
        
        
        while(l1 != nullptr && l2 != nullptr){
            tmp = l1->val + l2->val;
            tmp += res;
            cur->next = new ListNode(tmp % 10);
            cur = cur->next;
            
            res = tmp / 10;
            l1 = l1->next, l2 = l2->next;
        }
        
        while (l1 != nullptr){
            tmp = l1->val;
            tmp += res;
            cur->next = new ListNode(tmp % 10);
            cur = cur->next;
            
            res = tmp / 10;
            l1 = l1->next;
        }
        
        while (l2 != nullptr){
            tmp = l2->val;
            tmp += res;
            cur->next = new ListNode(tmp % 10);
            cur = cur->next;
            
            res = tmp / 10;
            l2 = l2->next;
        }
        
        if (res > 0){
            cur->next = new ListNode(res);
            cur = cur->next;
            return ans;
        }
        else{
            return ans;
        }
        
    }
};


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
