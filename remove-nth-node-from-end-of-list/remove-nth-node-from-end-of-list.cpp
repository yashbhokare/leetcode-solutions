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
        ListNode* dummyNode=new ListNode(0);
        dummyNode->next=head;
        ListNode* pos=dummyNode;
        while(n>0){
            pos=pos->next;
            n--;
        }
        ListNode* val=dummyNode;
        while(pos->next!=NULL){
            val=val->next;
            pos=pos->next;
        }
        
        val->next=val->next!=NULL ? val->next->next : NULL;
        return dummyNode->next;

    }
};