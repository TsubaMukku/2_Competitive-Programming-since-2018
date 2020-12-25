

// TLE code
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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        
        ListNode *cur = head;
        head = head->next;
        
        while (cur != nullptr  &&  cur->next != nullptr){
            ListNode *keep = cur->next;
            cur->next->next = cur;
            cur->next = keep->next;
            cur = cur->next;
        }
        
        return head;
    }
};
