

// 2021/01/26
// brute force
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        vector<int> tmp;
        
        ListNode *head = new ListNode(0);
        ListNode *point = head;
        
        for (auto x : lists){
            while (x){
                tmp.emplace_back(x->val);
                x = x->next;
            }
        }
        
        sort(tmp.begin(),tmp.end());
        
        for (auto x : tmp){
            point->next = new ListNode(x);
            point = point->next;
        }
        
        return head->next;
        
        
    }
};
