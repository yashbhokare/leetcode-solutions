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
public:
    unordered_map<Node*,Node*> mapper;
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        if(mapper.find(node)!=mapper.end()) return mapper[node];
        
        Node* newNode = new Node(node->val);
        mapper[node] = newNode;
        for(auto neighbor:node->neighbors){
            newNode->neighbors.push_back(cloneGraph(neighbor));
        }
        
        return mapper[node];
        
    }
};