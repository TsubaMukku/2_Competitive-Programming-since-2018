

// 2021/02/10
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
    int index = 0;
    map<int,int> mp;
    
    void traverseBST(TreeNode *root){
        if (root){
            traverseBST(root->right);
            mp[root->val]++;
            traverseBST(root->left);
        }
    }
    
public:
    int kthSmallest(TreeNode* root, int k) {
        traverseBST(root);
        
        for (auto p : mp){
            index++;
            if (index == k){
                int val = p.first;
                return val;
            }
        }
        
        return index;
    }
};
