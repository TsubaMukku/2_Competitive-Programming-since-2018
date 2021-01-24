

// 2021/01/24
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        
        // base case: either t1 or t2 is nullptr
        if (t1 == nullptr) return t2;
        if (t2 == nullptr) return t1;
        
        // both t1 and t2 are not nullptr
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left,t2->left);
        t1->right = mergeTrees(t1->right,t2->right);
        
        return t1;
        
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
    
    /*
    実装方針: the recursive approach
    1. preorderでNodeを渡っていく->なぜならその動きが一番自然だから
    2. 親の値のsumを計算して, それをt1に格納する
    3. leftをみた後, rightもみる
    
    */
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr) return t2;
        if (t2 == nullptr) return t1;
        
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left,t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        
        
        return t1;
    }
};


// 2021/01/22
// mergeの操作の実装がわからなかった
