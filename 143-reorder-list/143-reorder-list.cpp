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
    void reorderList(ListNode* head) {
        ListNode* middle=middle_element(head);
        ListNode* p1=head;
        ListNode* p2=reverse_list(middle->next);
        middle->next=NULL;
        merge(p1,p2);
        // return head;
    }
    
    ListNode* middle_element(ListNode* head){
        ListNode* slow= head;
        ListNode* fast= head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    ListNode* reverse_list(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr= head;
        while(curr){
            ListNode* next_node = curr->next;
            curr->next=prev;
            prev=curr;
            curr=next_node;
        }
        return prev;
        
    }
    
   void merge(ListNode* p1,ListNode* p2){
        // ListNode* curr = new ListNode(0);
        while(p1 && p2){
            ListNode* temp1 = p1->next;
            // Add element in between
            p1->next=p2;
            
            ListNode* temp2=p2->next;
            
            p2->next=temp1;
        
            p1=temp1;
            p2=temp2;
        }
    }
};