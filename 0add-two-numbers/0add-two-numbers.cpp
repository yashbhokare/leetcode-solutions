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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head= new ListNode(0);
        ListNode* curr=head;
        int carry=0;
        while(l1!=NULL || l2!=NULL || carry){
            int val1= l1 ? l1->val : 0;
            int val2= l2 ? l2->val : 0;
            
            int sum=val1+val2+carry;
            carry=sum/10;
            int val=sum%10;
            curr->next=new ListNode(val);
            curr=curr->next;
            
            l1= l1 ? l1->next : NULL;
            l2= l2 ? l2->next : NULL;
        }
        return head->next;
    }
};