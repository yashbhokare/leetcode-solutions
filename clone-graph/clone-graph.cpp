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
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        return cloneGraphCal(node);
    }
    
    Node* cloneGraphCal(Node* node){
        auto it = mapper.find(node->val);
        if(it != mapper.end()){
            return it->second;
        }
        Node* newVal = new Node(node->val);
        mapper.insert({node->val,newVal});
        for(auto neighbour: node->neighbors){
            newVal->neighbors.push_back(cloneGraphCal(neighbour));
        }
        return newVal;
    }
    
    
};