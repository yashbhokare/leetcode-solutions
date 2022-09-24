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
    Node* connect(Node* root){
        return connect_using_constant_space(root);
    }
    Node* connect_using_constant_space(Node* root) {
        if(root == NULL) return root;
        
        Node* head = root;
        Node* nextValid = root;
        while(nextValid!=NULL){
            
            Node* level = nextValid;
            Node* prev = NULL;
            nextValid =NULL;
            //**** Order of if conditions very important *****
            while(level){
                // If no child exists move to next parent
                if(level->left==NULL && level->right==NULL){
                    level = level->next;
                    continue;
                }
                // First pref given to left node 
                if(level->left!=NULL && prev){
                    prev->next=level->left;
                    prev = prev->next;
                }
                
                // Store the prev element if it doesn't exist 
                if(level->left!=NULL && prev==NULL){
                    prev=level->left;
                    nextValid = prev;
                }
                
                // Check if right child exists if prev exists
                if(level->right!=NULL && prev){
                    prev->next=level->right;
                    prev = prev->next;
                }
                
                // Store the prev element if it doesn't exist 
                if(level->right!=NULL && prev==NULL){
                    prev=level->right;
                    nextValid = prev;
                }
                level = level->next;
            }
            // head = nextValid->left ? nextValid->left : nextValid->right;
            // nextValid = nextValidNode(head);
        }
        return root;
    }
    
    Node* nextValidNode(Node* root){
        Node* nextNode=NULL;
        while(root){
            if(root->left){
                nextNode=root;
                break;
            }else if(root->right){
                nextNode=root;
                break;
            }
            root=root->next;
        }
        return nextNode;
    }
    
    Node* connect_using_bfs(Node* root) {
        if(root == NULL) return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                Node* current = q.front();
                q.pop();
                if(i+1>=size){
                    current->next = NULL;
                }else {
                    Node* next = q.front();
                    current->next = next;
                }
                if(current->left!=NULL) q.push(current->left);
                if(current->right!=NULL) q.push(current->right);
            }
        }
        return root;
    }
};