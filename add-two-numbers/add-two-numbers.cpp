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
        int sum = 0;
        int carry = 0;
        ListNode* head_result = new ListNode(0);
        ListNode* result = head_result;
        while(l1 != NULL || l2!=NULL){
            int val1 = l1 ? l1->val : 0 ;
            int val2 = l2 ? l2->val : 0 ;
            
            sum = val1+val2 + carry;
            carry = sum/10;
            sum = sum%10;
            
            result->next = new ListNode(sum);
            result = result->next;
            
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL; 
        }
        if(carry == 1){
            result->next= new ListNode(1);
        } 
        return head_result->next;
    }
};