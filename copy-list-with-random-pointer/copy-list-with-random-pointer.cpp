/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(head==NULL) return head;
        Node* curr=head;
        // Insert new nodes inbetween existing nodes
        while(curr!=NULL){
            Node* newVal=new Node(curr->val);
            newVal->next=curr->next;
            curr->next=newVal;
            curr=curr->next->next;
        }
        curr=head;
        // Find the random pointers for new nodes
        while(curr!=NULL && curr->next!=NULL){
            Node* newNode=curr->next;
            newNode->random=curr->random!=NULL ? curr->random->next : NULL;
            curr=curr->next->next;
        }
        
        // Detach the new nodes
        curr=head;
        Node* newHead=head->next;
        while(curr!=NULL && curr->next!=NULL){
            Node* newNode=curr->next;
            
            //Attach the old pointers
            curr->next=newNode->next;
            
            //Attach the new pointers
            newNode->next= newNode->next ? newNode->next->next : NULL;
            
            curr=curr->next;
        }
        // curr=head;
        // while(curr!=NULL){
        //     cout<<curr->val<<" ";
        //     curr=curr->next;
        // }
        
        return newHead;
        
    }
};