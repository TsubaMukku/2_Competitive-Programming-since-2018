

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        stack<Node*> st;
        vector<int> ans;
        
        if (root == nullptr) return ans;
        
        st.push(root);
        
        while (!st.empty()){
            Node *node = st.top();
            st.pop();
            
            ans.emplace_back(node->val);
            
            reverse(node->children.begin(),node->children.end());
            
            for (Node *item : node->children) st.push(item);
        }
        
        return ans;
        
    }
};
