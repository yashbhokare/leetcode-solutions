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

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        return bfs(root);
    }
    
    vector<vector<int>> bfs(Node* root){
        if(root==NULL) return {};
        
        vector<vector<int>> result;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> levelResult;
            while(size--){
                Node* temp = q.front();
                q.pop();
                levelResult.push_back(temp->val);
                for(auto node:temp->children){
                    if(node!=NULL) q.push(node);
                }
            }
            result.push_back(levelResult);
        }
        return result;
    }
};