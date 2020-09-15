/*
    cited from https://leetcode.com/problems/inorder-successor-in-bst/discuss/72741/C%2B%2B-iterative
    
    If p has a right subtree, then its successor is the leftmost child of that subtree. Otherwise, the successor of p should have p in its left subtree.
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        
        TreeNode *next = nullptr;
        
        if (p->right){
            next = p->right;
            
            while (next->left) next = next->left;
            
            return next;
        }
        
        while (root != nullptr){
            
            if (p->val < root->val){
                next = root;
                root = root->left;
            }
            else if (root->val < p->val){
                root = root->right;
            }
            else break;
        }
        
        return next;
    }
};
