// BFS

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        
        if (root == nullptr) return 0;
        int ans = 0;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()){
            ans++;
            int breadth = q.size();
            
            for (int i = 0; i < breadth; i++){
                TreeNode *cur = q.front();
                q.pop();
                if (cur->left != nullptr) q.push(cur->left);
                if (cur->right != nullptr) q.push(cur->right);
            }
        }
        
        return ans;
    }
};


// iteration
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        
        stack<pair<TreeNode*, int>> st;
        
        st.push({root,1});
        
        int res = 0;
        
        while (!st.empty()){
            auto p = st.top();
            st.pop();
            
            TreeNode *cur = p.first;
            int depth = p.second;
            
            if (cur->left != nullptr) st.push({cur->left,depth+1});
            if (cur->right != nullptr) st.push({cur->right,depth+1});
            
            res = max(res,depth);
            
            
        }
        return res;
    }
};
