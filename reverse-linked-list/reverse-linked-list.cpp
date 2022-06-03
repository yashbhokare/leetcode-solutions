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
    ListNode* reverseList(ListNode* head) {
        
        if(head==NULL) return head;
        ListNode* curr=head;
        while(curr->next!=NULL){
            ListNode* temp = curr->next;
            // Remove element
            curr->next=curr->next->next;
            
            // Add to the top
            temp->next=head;
            head=temp;
            
        }
        return head;
    }
};