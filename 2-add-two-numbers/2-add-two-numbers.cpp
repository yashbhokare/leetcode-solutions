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
        ListNode* head = new ListNode(0);
        ListNode* temp = head;
        
        int carry = 0;
        while(l1!=NULL || l2!=NULL){
            int l1Value = l1==NULL ? 0 : l1->val;
            int l2Value = l2==NULL ? 0 : l2->val;
            int sum = l1Value + l2Value + carry;
        
            carry = sum /10;
            sum = sum%10;
            temp->next= new ListNode(sum);
            temp=temp->next;
            
            l1 = l1==NULL ? NULL : l1->next;
            l2 = l2==NULL ? NULL : l2->next;
        }
        
        if(carry==1) temp->next= new ListNode(1);
        return head->next;
    }
};