// 2020-09-18

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
    int maxDepth(Node* root) {
        
        
        // From the definition, an intuitive idea would be to traverse the tree and record the maximum depth during the traversal.
        
        // DFS
        
        if (root == nullptr) return 0;
        int depth = 0;
        for (auto child : root->children) depth = max(depth,maxDepth(child));
        
        return depth+1;
    }
};


// BFS
class Solution {
public:
    int maxDepth(Node* root) {
        
        if (root == nullptr) return 0;
        
        queue<Node*> q;
        q.push(root);
        int depth = 0;
        
        while (!q.empty()){
            depth++;
            
            int breadth = q.size();
            
            for (int j = 0; j < breadth; j++){
                auto node = q.front();
                q.pop();
                
                for (auto child : node->children){
                    if (child != nullptr) q.push(child);
                }
            }
        }
        
        return depth;
         
    }
};

// iterative
class Solution {
public:
    int maxDepth(Node* root) {
        
        if (root == nullptr) return 0;
        
        stack<pair<Node*,int>> stack;
        
        stack.push({root,1});
        
        int depth = 0;
        
        while (!stack.empty()){
            
            auto p = stack.top();
            stack.pop();
            
            Node *cur = p.first;
            int cur_depth = p.second;
            
            for (auto child : cur->children){
                stack.push({child,cur_depth+1});
            }
            
            depth = max(depth,cur_depth);
        }
        
        return depth;
    }
};
