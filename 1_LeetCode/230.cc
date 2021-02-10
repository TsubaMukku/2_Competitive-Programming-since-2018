

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
    void inorder(TreeNode *root, vector<int> &nums){
        if (root == nullptr) return;
        inorder(root->left,nums);
        nums.emplace_back(root->val);
        inorder(root->right,nums);
        return;
    }
    
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> nums;
        inorder(root,nums);
        return nums[k-1];
    }
};

/*
なぜその解法が思い付かなかったのか
・先ほど解いた問題の解法に頭が引っ張られてしまった
・inorder traversal of BST is an array sorted in the ascending order.という知識を覚えていなかった

どういう思考が足りなかったのか
・norder traversal of BST is an array sorted in the ascending order.という考え方
・tree上のtraversalでは dfs, bfsをまず考える、という原則が頭に入っていなかった


もし必要とされる思考法が足りていたとしたら解法を思い付けたのか
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
