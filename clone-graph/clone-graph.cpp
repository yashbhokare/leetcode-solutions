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
    unordered_map<int,Node*> mapper;
    Node* recCloneGraph(Node* node){
        if(node==NULL) return node;
        auto it= mapper.find(node->val);
        if(it!=mapper.end()){
            return it->second;
        }
        Node* newNode=new Node(node->val);
        mapper[node->val]=newNode;
        
        for(auto& neighbor:node->neighbors){
            newNode->neighbors.push_back(recCloneGraph(neighbor));
        }
        return newNode;
    }
    
    Node* cloneGraph(Node* node) {
        return recCloneGraph(node);
    }
};