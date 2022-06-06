/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* posA = headA;
        ListNode* posB = headB;
        if(posA==NULL || posB==NULL) return NULL;
        
        while(posA!=posB){
            posA = posA->next;
            posB = posB->next;
            
            if(posA==posB) return posA;
            
            if(posA==NULL) posA=headB;
            if(posB==NULL) posB=headA;
        }
        return posA;
    }
};