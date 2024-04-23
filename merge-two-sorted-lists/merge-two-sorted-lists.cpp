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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head= new ListNode(0);
        ListNode* curr=head;
        while(list1 && list2){
            int l1 = list1->val;
            int l2 = list2->val;
            
            if(l1<l2){
                curr->next=list1;
                list1=list1->next;
            }else{
                curr->next=list2;
                list2=list2->next;
            }
            curr=curr->next;
        }
        curr->next = list1 ? list1 : list2;
        return head->next;
    }
};