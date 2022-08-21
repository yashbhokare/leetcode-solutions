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
        ListNode* newList = new ListNode(0);
        ListNode* head = newList;
        while(list1 && list2){
            int temp;
            if(list1->val <= list2->val){
                temp = list1->val;
                list1=list1->next;
            }else {
                temp = list2->val;
                list2=list2->next;
            }
            newList->next =  new ListNode(temp);
            newList = newList->next;
        }
        
        newList->next = list1 != NULL ? list1 : list2; 
        return head->next;
    }
};