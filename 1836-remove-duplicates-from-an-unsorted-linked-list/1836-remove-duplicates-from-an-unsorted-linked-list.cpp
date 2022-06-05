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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        unordered_map<int,int> numSet;
        ListNode* temp_head=new ListNode(0);
        temp_head->next=head;
        ListNode* temp=head;
        while(temp!=NULL){
            numSet[temp->val]++;
            temp=temp->next;
        }
        
        temp=temp_head;
        while(temp->next!=NULL){
            if(numSet[temp->next->val]>1){
                temp->next=temp->next->next;  
            }else {
                temp=temp->next;
            }
        }
        return temp_head->next;
    }
};