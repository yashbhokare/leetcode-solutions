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
        ListNode* oddHead=head;
        ListNode* evenHead=new ListNode(0);
        
        ListNode* evenVal=evenHead;
        ListNode* oddVal=oddHead;
        ListNode* tempEvenVal;
        

        while(oddVal->next!=NULL){
            // cout<<oddVal->val<<" ";
            tempEvenVal=oddVal->next;
            //Remove even number
            oddVal->next=oddVal->next!=NULL ? oddVal->next->next : NULL;
            oddVal=oddVal->next!=NULL ? oddVal->next : oddVal;
            // cout<<oddVal->val<<endl;
            //Add the even number
            evenVal->next=tempEvenVal;
            evenVal=evenVal->next;
        }
        evenVal->next=NULL;
        oddVal->next=evenHead->next;
        // while(oddHead!=NULL){
        //     cout<<oddHead->val<<" ";
        //     oddHead=oddHead->next;
        // }
        return head;
        
    }
};