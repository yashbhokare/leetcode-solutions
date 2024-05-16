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
    unordered_map<int,Node*> map;
    
    Node* recursion(Node* node ){
        if(node==NULL) return NULL;
        if(map.find(node->val)!=map.end()){
            return map[node->val];
        }
        Node* newNode=new Node(node->val);
        map.insert({node->val,newNode});
        for(auto child:node->neighbors){
            newNode->neighbors.push_back(recursion(child));
        }
        return newNode;
    }
    
    Node* cloneGraph(Node* node) {
        return recursion(node);
    }
};