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
        // if(head==NULL) return head;
        ListNode* curr=head;
        while(curr && curr->next){
            
            ListNode* temp=curr->next;
            
            // Delete the next node
            curr->next=curr->next->next;
            
            //Add the deleted node on head
            
            temp->next=head;
            head=temp;
        }
        return head;
    }
};