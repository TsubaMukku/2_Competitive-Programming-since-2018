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

// https://leetcode.com/problems/n-ary-tree-level-order-traversal/discuss/159086/Basic-C%2B%2B-iterative-solution-with-detailed-explanations.-Super-easy-for-beginners.

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        if (root == nullptr) return vector<vector<int>>();
        
        vector<vector<int>> res;
        
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()){
            
            int cur_size = q.size();
            
            vector<int> cur_contents;
            
            for (int i = 0; i < cur_size; i++){
                Node *tmp = q.front();
                q.pop();
                cur_contents.emplace_back(tmp->val);
                
                for (auto child : tmp->children) q.push(child);
            }
            
            res.emplace_back(cur_contents);
        }
        
        return res;
        
    }
};
