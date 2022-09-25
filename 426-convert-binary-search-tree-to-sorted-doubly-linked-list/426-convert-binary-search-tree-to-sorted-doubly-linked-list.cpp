/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* prev;

    Node* treeToDoublyList(Node* root) {
        if(root==NULL) return NULL;
        prev=new Node(-1);
        Node* head = prev;
        rec(root);
        head= head->right;
        prev->right=head;
        head->left=prev;

        return head;
    }
    
    
    void rec(Node* root){
        if(root==NULL) return;
        rec(root->left);
        prev->right = root;
        root->left=prev;
        prev=root;
        rec(root->right);
    }
};