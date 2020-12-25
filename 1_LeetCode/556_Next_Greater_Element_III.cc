class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        
        int i = s.size()-2;
        
        while (i >= 0 && s[i] >= s[i+1]) i--;
        
        if (i < 0) return -1;
        
        int j = s.size()-1;
        
        while (j >= 0 && s[i] >= s[j])j--;
        
        swap(s[i],s[j]);
        reverse(s.begin()+i+1,s.end());
        
        long long ans = stoll(s);
        if (ans > INT_MAX) return -1;
        else return (int)ans;
    }
};


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
