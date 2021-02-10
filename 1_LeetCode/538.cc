
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
    int total = 0;
    
public:
    TreeNode* convertBST(TreeNode* root) {
        if (root != nullptr){
            convertBST(root->right);
            total += root->val;
            root->val = total;
            convertBST(root->left);
        }
        
        return root;
    }
};

/*

なぜその解法が思い付かなかったのか
・問題を解く上で鍵となる操作が何であるか、そこを把握できなかった
（具体例から、動きを見抜けなかった）


どういう思考が足りなかったのか
・問題を解く鍵が「それぞれのnodeを, 単調減少順に、一度だけ訪れること」、
「それまで訪れたnodeのvalを保存しておくこと」
にあるという考えが足りなかった


もし必要とされる思考法が足りていたとしたら解法を思い付けたのか
・難しかったと思う。それをバグらずに実装できたかどうか、自信がない


*/
