

// 2021/01/14
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;
        
        ListNode *cur = head;
        
        while (cur != nullptr){
            if (cur->next != nullptr && cur->val == cur->next->val){
                cur->next = cur->next->next;
            }
            else{
                cur = cur->next;
            }
        }
        
        return head;
    }
};

// 2021/01/10
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;
        
        ListNode *cur = head;
        
        while (cur != nullptr){
            
            if (cur->next != nullptr && cur->val == cur->next->val){
                cur->next = cur->next->next;
            }
            else{
                cur = cur->next;
            }
        }
        
        return head;
    }
};


// 2021/01/08
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        // corner case
        if (head == nullptr) return head;
        
        ListNode *tmp = head;
        
        while (tmp != nullptr && tmp->next != nullptr){
            
            ListNode *go = tmp;
            
            if (go->val == go->next->val){
                while (go->next != nullptr && go->val == go->next->val){
                    go = go->next;
                }
                tmp->next = go->next;
                tmp = tmp->next;
            }
            else{
                tmp = tmp->next;
            }
        }
        
        return head;
    }
};




// 2021/01/06

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
    ListNode* deleteDuplicates(ListNode* head) {
        
        // corner case
        if (head == nullptr) return head;
        
        ListNode *ans = new ListNode(head->val);
        ListNode *tmp = ans;
        ListNode *first = head;
        ListNode *second = first->next;
        
        while (second != nullptr){
            if (first->val == second->val){
                first = first->next;
                second = second->next;
            }
            else{
                tmp->next = new ListNode(second->val);
                tmp = tmp->next;
                first = first->next;
                second = second->next;
            }
        }
        
        return ans;
    }
};
