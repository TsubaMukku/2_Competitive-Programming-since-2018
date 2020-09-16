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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if (head == nullptr) return head;
        
        int node_num = 1;
        
        ListNode *new_head = head;
        ListNode *tail = head;
        
        while (tail->next != nullptr){
            tail = tail->next;
            node_num++;
        }
        
        tail->next = head;
        
        k %= node_num;
        if (k != 0){
            for (int i = 0; i < (node_num-k); i++){
                tail = tail->next;
            }
        }
        
        new_head = tail->next;
        tail->next = nullptr;
        return new_head;
    }
};
