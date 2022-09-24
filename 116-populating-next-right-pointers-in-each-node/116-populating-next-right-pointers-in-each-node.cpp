/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        return connect_using_no_space(root);
        // return connect_using_bfs(root);
    }
    
    // Using O(1) Space complexity
    Node* connect_using_no_space(Node* root) {
        if(root==NULL) return NULL;
        Node* head=root;
        Node* leftMost=root;
        while(leftMost->left){
            Node* node = leftMost;
            while(node!=NULL){
                // Connection 1
                node->left->next=node->right;
                
                // Connection 2
                if(node->next){
                    node->right->next=node->next->left;
                }
                
                node=node->next;
            }
            leftMost=leftMost->left;
        }
        return root;
    }
    
    Node* connect_using_bfs(Node* root) {
        if(root==NULL) return root;
        queue<Node*> q;
        Node* head = root;
        q.push(root);
        while(!q.empty()){
            int qSize = q.size();
            while(qSize){
                Node* node = q.front();
                q.pop();
                if(qSize>1){
                    node->next = q.front();
                }
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
                qSize--;
            }
        }
        return head;
    }

    
};