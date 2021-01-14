

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
private:
    ListNode *reverseList(ListNode *l){
        ListNode *pre = nullptr;
        ListNode *cur = l;
        
        while (cur != nullptr){
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
    
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        
        int tmp = l1->val + l2->val;
        l1 = l1->next, l2 = l2->next;
        int res = tmp / 10;
        ListNode *ans = new ListNode(tmp%10);
        ListNode *cur = ans;
        
        while (l1!= nullptr && l2 != nullptr){
            tmp = l1->val + l2->val;
            l1 = l1->next, l2 = l2->next;
            tmp += res;
            
            cur->next = new ListNode(tmp%10);
            res = tmp / 10;
            cur = cur->next;
        }
        while(l1!= nullptr){
            tmp = l1->val;
            l1 = l1->next;
            tmp += res;
            
            cur->next = new ListNode(tmp%10);
            res = tmp / 10;
            cur = cur->next;
        }
        while(l2!= nullptr){
            tmp = l2->val;
            l2 = l2->next;
            tmp += res;
            
            cur->next = new ListNode(tmp%10);
            res = tmp / 10;
            cur = cur->next;
        }
        
        if (res > 0){
            cur->next = new ListNode(res);
            cur = cur->next;
        }
        
        ans = reverseList(ans);
        return ans;
    }
};




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


/*
  solution 2: reverse lists -> push into stacks -> pop each element -> 今度はstack空になるまで
  順番に取り出せば良い -> 取り出すたびにLinkedListを伸ばしていく.
  
  time complexity: O(n + m)
  space complexity: O(n + m)
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
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*> s1;
        stack<ListNode*> s2;
        stack<ListNode*> s3;
        
        while (l1 != nullptr){
            s1.push(l1);
            l1 = l1->next;
        }
        
        while (l2 != nullptr){
            s2.push(l2);
            l2 = l2->next;
        }
        
        int carry = 0;
        int val1, val2;
        
        while (!s1.empty() || !s2.empty()){
            
            if (s1.empty()) val1 = 0;
            else{
                val1 = s1.top()->val;
                s1.pop();
            }
            
            if (s2.empty()) val2 = 0;
            else{
                val2 = s2.top()->val;
                s2.pop();
            }
            
            int val = val1 + val2 + carry;
            
            ListNode* node = new ListNode(val % 10);
            carry = val / 10;
            s3.push(node);
        }
        
        if (carry > 0) s3.push(new ListNode(carry));
        
        ListNode* dummy = new ListNode(0);
        
        ListNode *node = dummy;
        
        while (!s3.empty()){
            node->next = s3.top();
            s3.pop();
            node = node->next;
        }
        
        return dummy->next;
    }
};

