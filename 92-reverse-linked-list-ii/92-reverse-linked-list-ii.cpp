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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* newHead = new ListNode(0);
        newHead->next=head;
        head = newHead;
        for(int i=1;i<left;i++){
            head = head->next;
        }
        head->next = reverseLinkedList(head->next,right-left);
        return newHead->next;
        
    }
    
     ListNode* reverseLinkedList(ListNode* head, int right){
        ListNode* curr = head;
        while(right--){
            ListNode* temp=curr->next;
            curr->next=curr->next->next;
            temp->next=head;
            head=temp;
        }
         return head;
    }
};