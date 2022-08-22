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
    ListNode* swapPairs(ListNode* head) {
        return swap(head);
    }
    
    ListNode* swap(ListNode* head){
        ListNode* newHead = new ListNode(0);
        newHead->next = head;
        ListNode* prev = newHead;
        // ListNode* curr = newHead->next;
        while(head!=NULL){
            ListNode* thirdPointer = NULL;
            if(head->next!=NULL && head->next->next!=NULL){
                 thirdPointer = head->next->next;
                head->next->next =NULL;
            }
               
            if(head->next!=NULL){
                // cout<<prev->val<<"->";
                prev->next = head->next;
                head->next = NULL;
                prev=prev->next;
            }
            // cout<<prev->val<<"->";
            prev->next=head;
            prev=prev->next;
            // cout<<prev->val<<"->";
            head = thirdPointer;
            // cout<<head<<"->";
        }
        
        return newHead->next;
        
    }
};