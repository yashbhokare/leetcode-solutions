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
        if(root==NULL) return root;
        queue<Node*> q;
        Node* head = root;
        q.push(root);
        while(!q.empty()){
            int qSize = q.size();
            while(qSize){
                Node* node = q.front();
                cout<<node->val<<" ";
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