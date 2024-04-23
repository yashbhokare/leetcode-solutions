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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* newHeadNode=new ListNode(0);
        newHeadNode->next=head;
        ListNode* pos=newHeadNode;
        while(n>0){
            pos=pos->next;
            n--;
        }
        ListNode* val=newHeadNode;
        while(pos->next!=NULL){
            val=val->next;
            pos=pos->next;
        }
        
        val->next=val->next!=NULL ? val->next->next : NULL;
        return newHeadNode->next;

    }
};