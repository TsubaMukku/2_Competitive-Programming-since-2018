

// 2021/02/11
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    unordered_map<Node*, Node*> mp;
    
public:
    Node* copyRandomList(Node* head) {
        
        if (head == nullptr) return nullptr;
        
        // already processed the current node
        // return the cloned version of it
        if (mp.count(head)){
            return mp[head];
        }
        
        // create a new node
        Node* node = new Node(head->val,nullptr,nullptr);
        
        // save this value in the hashmap
        mp[head] = node;
        
        node->next = copyRandomList(head->next);
        node->random = copyRandomList(head->random);
        
        return node;
    }
    
    
};

/*
なぜその解法が思い付かなかったのか
・randomポインタの処理がわからなかった（具体例から法則を見抜けなかった）


どういう思考が足りなかったのか
・consider the linked list like a graph
・we can see the random pointer points back to the previously seen node hence leading to a cycle. We need to take care of these cycles in the implementation.
・linked listではなく、グラフのクローニングという発想の転換ができなかった（第一、graph cloningを解いたことがなかったので思いつくわけがない）


もし必要とされる思考法が足りていたとしたら解法を思い付けたのか
*/
