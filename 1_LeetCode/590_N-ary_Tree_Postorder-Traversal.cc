/*
Q:
Given an n-ary tree, return the postorder traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal, 
each group of children is separated by the null value (See examples).


*/


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

/*
binary treeと同様の発想をする
左の子　→　右の子　→　親　というルートでたどる

base case:
leafにたどり着いた時：childrenのサイズが0である->valを答えの配列に格納する.

それぞれのchildをへ潜る(dfsっぽく)
最後に, 自分のvalを答えの配列に格納する
*/


// an iterative solution
class Solution {
public:
    vector<int> postorder(Node* root) {
        stack<Node*> st;
        vector<int> ans;
        
        if (root == nullptr) return ans;
        
        st.push(root);
        
        while (!st.empty()){
            
            Node *temp = st.top();
            st.pop();
            
            for (auto child: temp->children) st.push(child);
            
            ans.emplace_back(temp->val);
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


// a recursive approach
class Solution {
public:
    void solve(Node *root, vector<int> &res){
        
        if (root->children.size() == 0){
            res.emplace_back(root->val);
            return;
        }
        
        for (Node *child : root->children){
            solve(child,res);
        }
        res.emplace_back(root->val);
        return;
    }

    vector<int> postorder(Node* root) {
        vector<int> res;
        if (root==nullptr) return res;
        
        solve(root,res);
        return res;
    }
};
