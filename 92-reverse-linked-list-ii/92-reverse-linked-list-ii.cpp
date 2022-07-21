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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* new_head = new ListNode(0);
        new_head->next = head;
        ListNode* startN = startNode(new_head,left);
        startN->next =reverseLinkedList(startN->next,right-left);
        return new_head->next;
    }
    
    ListNode* reverseLinkedList(ListNode* head,int count){
        // ListNode* new_head = new ListNode(0);
        // new_head->next = head;
        ListNode* temp = head;
        // cout<<count;
        while(count){
            // Remove node
            ListNode* node = temp->next;
            temp->next=temp->next->next;
            
            // Add to the top
            node->next=head;
            head=node;
            cout<<head->val;
            count--;
        }
        return head;
    }
    
    ListNode* startNode(ListNode* head, int left){
        while(left>1){
            head=head->next;
            left--;
        }
        return head;
    }
};