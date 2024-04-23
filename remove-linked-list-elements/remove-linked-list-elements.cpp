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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* newHead= new ListNode(0);
        newHead->next=head;
        ListNode* p=newHead;
        while(p->next!=NULL){
            if(p->next->val==val){
                p->next=p->next->next;
            }else {
                p=p->next;
            }
        }
        return newHead->next;
    }
};