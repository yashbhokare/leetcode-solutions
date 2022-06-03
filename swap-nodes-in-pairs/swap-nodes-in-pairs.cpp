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
        return recSwapPairs(head);
    }
    
    ListNode* recSwapPairs(ListNode* head) {
        ListNode* third = NULL;
        if(head== NULL || head->next==NULL){
            return head;
        }
        // else {
        //     third = recSwapPairs(head->next->next);
        // }
        
        
        ListNode* second = head->next;
        
        head->next = recSwapPairs(head->next->next);;
        
        // Swap first and second
        second->next= head;
        // first->next = third;
        
        return second;
        
    }
};