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
    void dfs(TreeNode *root, vector<int> &v){
        
        if (root->left != nullptr) dfs(root->left,v);
        v.emplace_back(root->val);
        if (root->right != nullptr) dfs(root->right,v);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res1, res2;
        vector<int> ans;
        
        if (root1 != nullptr) dfs(root1,res1);
        if (root2 != nullptr) dfs(root2,res2);
        
        int pos1 = 0, pos2 = 0;
        
        while (pos1 < res1.size() && pos2 < res2.size()){
            
            if (res1[pos1] < res2[pos2]) ans.emplace_back(res1[pos1++]);
            else ans.emplace_back(res2[pos2++]);
        }
        
        while (pos1 < res1.size()) ans.emplace_back(res1[pos1++]);
        while (pos2 < res2.size()) ans.emplace_back(res2[pos2++]);
        return ans;
        
    }
};
