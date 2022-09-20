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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* curr=head;
        while(l1 && l2){
            int v1 = l1->val;
            int v2 = l2->val;
            if(v1<v2){
                curr->next=l1;
                l1=l1->next;
            }else {
                curr->next=l2;
                l2=l2->next;
            }
            curr=curr->next;
        }
        curr->next = l1 ? l1 : l2;
        return head->next;
    }
};