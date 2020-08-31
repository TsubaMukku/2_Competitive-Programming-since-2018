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
private:
    // root->valの値よりも, ちょうど一つ手前の小さい数を持つノードを返す
    int predecessor(TreeNode *root){
        root = root->left;
        
        while (root->right != nullptr) root = root->right;
        
        return root->val;
    }
    
    // root->valの値よりも, ちょうど一つ大きい数を持つノードを返す
    int successor(TreeNode *root){
        root = root->right;
        
        while (root->left != nullptr) root = root->left;
        
        return root->val;
    }
    
public:
    
    // rootから, keyを持つノードを消去する
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if (root == nullptr) return nullptr;
        
        
        // 消去すべきノードは, 右の部分木にある.
        if (root->val < key){
            
            root->right = deleteNode(root->right,key);
            
        }
        else if (key < root->val){
            
            root->left = deleteNode(root->left,key);
            
        }
        else{
            
            // そのノードがleafであれば, 単純に消去すれば良い
            if (root->left == nullptr && root->right == nullptr) root = nullptr;
            else if (root->right != nullptr){
                root->val = successor(root);
                root->right = deleteNode(root->right,root->val);
            }
            else{
                root->val = predecessor(root);
                root->left = deleteNode(root->left,root->val);
            }
            
        }
        
        return root;
        
    }
};
