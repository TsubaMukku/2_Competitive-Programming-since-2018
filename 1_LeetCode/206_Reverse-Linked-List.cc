/*
  この問題も, アイデアを知っているか知らないかの勝負である.
*/

// 2021/01/13
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = nullptr;
        ListNode *cur = head;
        
        while (cur != nullptr){
            ListNode *tmp = cur->next;
            
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        
        return pre;
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
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *cur = head;
        
        while (cur != nullptr){
            ListNode *temp = cur->next;
            cur->next = prev;
            
            prev = cur;
            cur = temp;
        }
        
        return prev;
    }
};
