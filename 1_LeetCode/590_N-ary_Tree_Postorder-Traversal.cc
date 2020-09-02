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
    vector<int> postorder(Node* root) {
        stack<Node*> st;
        vector<int> ans;
        
        if (root == nullptr) return ans;
        
        st.push(root);
        
        while (!st.empty()){
            
            Node *temp = st.top();
            st.pop();
            
            for (auto child: temp->children) st.push(child);
            
            ans.emplace_back(temp->val);
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
