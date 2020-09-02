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
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> ans;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* n = s.top();
            s.pop();
            ans.push_back(n->val); // O(1)
            if (n->left) s.push(n->left);
            if (n->right) s.push(n->right);
        }   
        return vector<int>(ans.rbegin(), ans.rend());
    }
};

// https://translate.google.com/translate?hl=en&sl=zh-CN&u=https://zxi.mytechroad.com/blog/tree/leetcode-145-binary-tree-postorder-traversal/&prev=search&pto=aue
