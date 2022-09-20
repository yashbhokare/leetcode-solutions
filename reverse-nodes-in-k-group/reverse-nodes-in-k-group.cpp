/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        return rec(head,k);
        
    }
    
    ListNode* rec(ListNode* root, int k) {
        if(root==NULL) return NULL;
       
        // Traverse till the last node of the subgroup
        int n=k;
        ListNode* temp=root;
        while(--n && temp->next){
            temp = temp->next;
        }
        
        if(n!=0) return root;
        
        ListNode* nextNode = rec(temp->next,k);
        ListNode* reverseHead = reverse(root,k);
        root->next=nextNode;
        return reverseHead;
    }
    
    ListNode* reverse(ListNode* head,int k){
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(k--){
            ListNode* nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        return prev;
    }
    
};