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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL) return NULL;
        return swap(head,head->next);
    }
    
    ListNode* swap(ListNode* first,ListNode* second){
        
        if(second==NULL) return first;
        
        ListNode* temp=second->next;
        second->next=first;
        first->next=temp==NULL ? NULL : swap(temp,temp->next);
        return second;
    }
};