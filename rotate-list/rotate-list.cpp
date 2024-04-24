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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        int n=0;
        ListNode* curr=head;
        ListNode* lastNode;
        while(curr!=NULL){
            n++;
            if(curr->next==NULL) lastNode=curr;
            curr=curr->next;
        }
        k=k%n;
        if(k==0) return head;
        
        ListNode* slow=head;
        while(k!=0){
            slow=slow->next;
            k--;
        }
        
        ListNode* fast=head;
        while(slow->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        
        ListNode* newHead=fast->next;
        fast->next=NULL;
        lastNode->next=head;
        return newHead;
        
    }
};