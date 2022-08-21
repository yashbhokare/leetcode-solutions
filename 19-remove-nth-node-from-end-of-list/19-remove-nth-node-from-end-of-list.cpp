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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* slow = dummyHead;
        ListNode* fast = dummyHead;
        
        for(int i=0;i<n;i++){
            fast = fast->next;
        }
        while(fast->next){
            slow = slow->next;
            fast=fast->next;
        }
        slow->next= slow->next!=NULL ? slow->next->next : NULL;
        return dummyHead->next;
        
    }
};