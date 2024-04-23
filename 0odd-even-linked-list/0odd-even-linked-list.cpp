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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL) return head;
        ListNode* odd=head;
        ListNode* even=head->next;
        ListNode* evenHead=head->next;
        while(even!=NULL && even->next!=NULL){
            odd->next=even->next;
            odd=odd->next;
            even->next=odd->next;
            even=even->next;
        }
        odd->next=evenHead;
        return head;
    
    }
//     ListNode* oddEvenList(ListNode* head) {
//         if(head==NULL || head->next==NULL || head->next->next==NULL) return head;
//         ListNode* oddHead=head;
//         ListNode* evenHead=new ListNode(0);
        
//         ListNode* evenVal=evenHead;
//         ListNode* oddVal=oddHead;
//         ListNode* tempEvenVal;
        
//         while(oddVal->next!=NULL){

//             tempEvenVal=oddVal->next;
//             //Remove even number
//             oddVal->next=oddVal->next!=NULL ? oddVal->next->next : NULL;
//             oddVal=oddVal->next!=NULL ? oddVal->next : oddVal;

//             //Add the even number
//             evenVal->next=tempEvenVal;
//             evenVal=evenVal->next;
//         }
//         // Add Null to last pointer
//         evenVal->next=NULL;
//         oddVal->next=evenHead->next;
//         return head;
        
//     }
};