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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* new_head = new ListNode(0);
        new_head->next = head;
        ListNode* slow = new_head;
        ListNode* fast = new_head;
        while(fast && fast->next && fast->next->next){
            slow= slow->next;
            fast= fast->next->next;
        }
        slow->next = slow->next ? slow->next->next : NULL;
        return new_head->next;
    }
};