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
        if(head == NULL) return NULL;
        ListNode* thead = head;
        ListNode* firstHalfEndVal = firstHalfEnd(thead);
        ListNode* p2 = reverseLinkedList(firstHalfEndVal->next);
        ListNode* p1 = head;
        
        while(p2!=NULL){
            if(p1->val != p2->val){
                return false;
            }
            p1 = p1->next;
            p2= p2->next;
        }

        return true;
    }
    
    ListNode* reverseLinkedList(ListNode* root){
        ListNode* node = root;
        
        while(node && node->next){
            // Remove element
            ListNode* temp = node->next;
            node->next = node->next->next;
            
            //Insert at head
            temp->next = root;
            root = temp;
        }
        return root;
    }
    
     ListNode* firstHalfEnd(ListNode* head){
        ListNode* slow =head;
        ListNode* fast =head;
         while(fast->next && fast->next->next){
             fast = fast->next->next;
             slow=slow->next;
         }
         return slow;
     }
};