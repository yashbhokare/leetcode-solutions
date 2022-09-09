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
        // Add a copy of new node after every other node
        if(head==NULL) return NULL;
        Node* curr = head;
        while(curr){
            Node* newNode = new Node(curr->val);
            newNode->next = curr->next;
            curr->next = newNode;
            curr=curr->next->next;
        }
        
        // Mark the random pointers of new Nodes
        curr = head;
         while(curr){  
            curr->next->random=curr->random == NULL ? NULL : curr->random->next;
            curr=curr->next->next;
         }
        
        // Delete the existing nodes
        Node* oldCurr = head;
        Node* newHead = head->next;
        curr = newHead;
        while(oldCurr && oldCurr->next){
            Node* temp = oldCurr->next;
            oldCurr->next = oldCurr->next->next;
            temp->next = oldCurr->next ? oldCurr->next->next : NULL;
            oldCurr = oldCurr->next;
        }
        
        return newHead;
        
    }
};