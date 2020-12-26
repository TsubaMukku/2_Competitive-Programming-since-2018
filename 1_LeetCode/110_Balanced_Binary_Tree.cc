

// 2020-12-26
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
    
    int height(TreeNode* root){
        if (root == nullptr) return -1;
        return 1 + max(height(root->left), height(root->right));
    }
    
    bool isBalanced(TreeNode* root) {
        
        
        // an empty tree satisfied the definition of a balanced tree
        if (root == nullptr) return true;
        
        // check if subtrees have height < 1.
        // if so, check if the subtrees are balanced
        
        return abs(height(root->left) - height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};
