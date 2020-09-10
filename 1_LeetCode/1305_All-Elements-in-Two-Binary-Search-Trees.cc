/*
    2020-09-11
*/

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
    void inorderTraversal(TreeNode *root, vector<int> &num){
        if (root == nullptr) return;
        
        if (root->left != nullptr) inorderTraversal(root->left,num);
        num.emplace_back(root->val);
        if (root->right != nullptr) inorderTraversal(root->right,num);
    }
    
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> num1;
        vector<int> num2;
        
        inorderTraversal(root1,num1);
        inorderTraversal(root2,num2);
        
        vector<int> ans;
        int n1 = (int)num1.size();
        int n2 = (int)num2.size();
        
        int i = 0, j = 0;
        while (i < n1 && j < n2){
            if (num1[i] < num2[j]){
                ans.emplace_back(num1[i]);
                i++;
            }
            else{
                ans.emplace_back(num2[j]);
                j++;
            }
        }
        
        while (i < n1){
            ans.emplace_back(num1[i]);
            i++;
        }
        while (j < n2){
            ans.emplace_back(num2[j]);
            j++;
        }
        
        return ans;
    }
};





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
