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
    void calc(int &res, string num){
        int i = (int)num.size()-1;
        int temp = 0;
        int multip = 1;
        while (i >= 0){
            temp += multip * (num[i] - '0');
            multip *= 2;
            i--;
        }
        
        res += temp;
        return;
    }
    
public:
    void sumRootToLeaf(TreeNode *root, int &res, string num){
        
        if (root->left == nullptr && root->right == nullptr){
            num += (root->val + '0');
            calc(res,num);
        }
        
        if (root->left != nullptr) {
            num += (root->val + '0');
            sumRootToLeaf(root->left, res, num);
        }
        if(root->right != nullptr) {
            num += (root->val + '0');
            sumRootToLeaf(root->right,res,num);
        }
        
        return;
        
    }
    int sumRootToLeaf(TreeNode* root) {
        int res = 0;
        string num = "";
        sumRootToLeaf(root,res,num);
        return res;
    }
};

/*
Output:
58 ?????

Expected:
22
*/


























/*
2020-09-08 19:38
以下のように書くと, 処理が動く

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
    
public:
    int sumRootToLeaf(TreeNode* root, int val = 0) {
        
        if ( root == nullptr) return 0;

        val = val * 2 + root->val;
        
        if ( root->left == nullptr && root->right == nullptr ) return val;
        else return sumRootToLeaf( root->left, val ) + sumRootToLeaf( root->right, val) ;
       
    }
};
