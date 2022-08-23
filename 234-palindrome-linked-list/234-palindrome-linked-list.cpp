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
    bool isPalindrome(ListNode* head) {
        ListNode* p1 = head;
        ListNode* midValue = midPoint(head);
        ListNode* p2 = reverse(midValue->next);
        while(p2!=NULL){
            if(p1->val!=p2->val) return false;
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }
    
    ListNode* midPoint(ListNode* head){
        ListNode* slow= head;
        ListNode* fast= head;
        while(fast && fast->next && fast->next->next){
            slow= slow->next;
            fast= fast->next->next;
        }
        return slow;
    }
    
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* start = head;
        while(curr && curr->next){
            
            ListNode* temp = curr->next;
            
            //Remove element
            curr->next = curr->next->next;
            
            temp->next = start;
            start = temp;

        }
        return start;
    }
};