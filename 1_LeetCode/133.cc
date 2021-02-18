

// 2021/02/18

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<Node*,Node*> visited;
public:
    Node* cloneGraph(Node* node) {
        
        if (node == nullptr) return nullptr;
        if (visited.count(node)) return visited[node];
        
        Node *clone = new Node(node->val);
         
        visited[node] = clone;
        
        for (auto neighbor : node->neighbors){
            clone->neighbors.emplace_back(cloneGraph(neighbor));
        }
        return clone;
    }
};
