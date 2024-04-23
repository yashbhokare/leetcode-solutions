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
        if(head==NULL || head->next==NULL) return head;
        ListNode* newHead=new ListNode(0);
        newHead->next=head;
        ListNode* p=head;
        while(p->next!=NULL){
            ListNode* removedNode=p->next;
            p->next=p->next!=NULL ? p->next->next : NULL;
            
            // Adding at the head
            removedNode->next=newHead->next;
            newHead->next=removedNode;
        }
        return newHead->next;
    }
};