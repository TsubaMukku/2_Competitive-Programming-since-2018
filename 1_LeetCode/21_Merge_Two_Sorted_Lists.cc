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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        vector<int> tmp;
        
        ListNode *first = l1;
        ListNode *second = l2;
        
        while (first != nullptr && second != nullptr){
            if (first->val <= second->val){
                tmp.emplace_back(first->val);
                first = first->next;
            }
            else{
                tmp.emplace_back(second->val);
                second = second->next;
            }
        }
        
        while(first != nullptr){
            tmp.emplace_back(first->val);
            first = first->next;
        }
        
        while (second != nullptr){
            tmp.emplace_back(second->val);
            second = second->next;
        }
        
        ListNode *ans = new ListNode(tmp[0]);
        for (int i = 1; i < tmp.size(); i++){
            ans->next = new ListNode(tmp[i]);
            ans = ans->next;
        }
        
        ans->next = nullptr;
        return ans;
    }
};
