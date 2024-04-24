/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head!=NULL) recursion(head);
        return head;
    }
    
    Node* recursion(Node* curr){
        while(curr->child!=NULL || curr->next!=NULL){
            if(curr->child!=NULL){
                Node* temp=curr;
                Node* endNode=recursion(curr->child);
                if(curr->next!=NULL){
                    curr->next->prev=endNode;
                }
                endNode->next=curr->next;
                endNode->child=NULL;
                
                curr->child->prev=curr;
                curr->next=curr->child;
                curr->child=NULL;
            }
            curr=curr->next;
        }
        return curr;
    }
};