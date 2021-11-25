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
        ListNode* head = new ListNode(0);
        ListNode* temp = head;
        while(list1!= NULL && list2!=NULL){
            int val1 = list1->val;
            int val2 = list2->val;
            
            if(val1<=val2){
                temp->next = list1;
                list1 = list1->next;
            }else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }
        temp->next = list1 ? list1 : list2;
        return head->next;
    }
};