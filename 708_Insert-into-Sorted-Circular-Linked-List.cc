/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        
         if (head == nullptr){
             Node *newNode = new Node(insertVal,nullptr);
             newNode->next = newNode;
             return newNode;
         }
        
        Node *prev = head;
        Node *cur = head->next;
        bool toInsert = false;
        
        do{
            
            if (prev->val <= insertVal && insertVal <= cur->val){
                toInsert = true;
            }
            else if (prev->val > cur->val){
                // しっぽまで来た場合を考える
                if (insertVal >= prev->val || insertVal <= cur->val){
                    toInsert = true;
                }
            }
            
            if (toInsert){
                prev->next = new Node(insertVal,cur);
                return head;
            }
            
            prev = cur;
            cur = cur->next;
            
        } while (prev != head);
        
        prev->next = new Node(insertVal,cur);
        return head;
    }
};
