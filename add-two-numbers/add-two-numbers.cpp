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
        ListNode* result = new ListNode(0);
        ListNode* head = result;
        int sum = 0,carry=0;
        while(l1!=NULL || l2!=NULL){
            int p1 = l1 ? l1->val : 0;
            int p2 = l2 ? l2->val : 0;
            
            sum = p1 + p2 + carry;
            if(sum>9){
                result->next = new ListNode(sum%10);
                carry = 1;
            }else {
                result->next = new ListNode(sum);
                carry = 0;
            }
            result = result->next;
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
            
        }
        if(carry ==1) result->next = new ListNode(1);
        return head->next;
    }
};




//         ListNode* result = new ListNode(0);
//         ListNode* temp = result;
//         int carry = 0;
//         while(l1 && l2){
//             int sum = l1->val+l2->val+carry;
//             cout<<sum<<" ";
//             if(sum<=9){
//                 temp->next = new ListNode(sum);
//                 carry = 0;
//             }else {
//                 carry = 1;
//                 temp->next = new ListNode(sum%10);
//             }
//             l1 = l1->next;
//             l2 = l2->next;
//             temp=temp->next;
//         }
//         // temp->next = l1 ? l1 :l2;
//         while(l1){
//             int sum = l1->val + carry;
//              if(sum<=9){
//                 temp->next = new ListNode(sum);
//                 carry = 0;
//             }else {
//                 carry = 1;
//                 temp->next = new ListNode(sum%10);
//             }
//             l1 = l1->next;
//             temp=temp->next;
//         }
        
//         while(l2){
//             int sum = l2->val + carry;
//              if(sum<=9){
//                 temp->next = new ListNode(sum);
//                 carry = 0;
//             }else {
//                 carry = 1;
//                 temp->next = new ListNode(sum%10);
//             }
//             l2 = l2->next;
//             temp=temp->next;
//         }
//         if(carry)  temp->next=new ListNode(1);
        
//         return result->next;