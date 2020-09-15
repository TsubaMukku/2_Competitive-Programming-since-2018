

/*
  2020/09/15　
  
  
*/


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        
        // the successor is somewhere lower in the right subtree
        if (node->right){
            node = node->right;
            
            while (node->left) node=node->left;
            return node;
        }
        
        // the successor is somewhere upper in the tree
        while (node->parent && node == node->parent->right){
            node = node->parent;
        }
        
        return node->parent;
    }
};
