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

    if(head == NULL) return head;
    
    ListNode* temp = new ListNode(0);
    temp->next = head;
    head= temp;
    
    ListNode* slow = head;
    ListNode* fast = head;
    for(int i=0;i<n;i++){
        fast = fast->next;
    }
     while(fast->next != NULL){
         slow = slow->next;
         fast=fast->next;
     } 
     slow->next = slow->next->next;
    return head->next;
    }
};

//     ListNode* removeNthFromEnd(ListNode* head, int n) {
        
//         int total = 0;
        
//         if(head == NULL) return head;    
//         ListNode* temp = new ListNode(0);
//         temp->next = head;
//         head = temp;
        
//         temp = head;
        
//         while(temp->next!=NULL){
//             total++;
//             temp=temp->next;
//         }
//         temp = head;
//         for(int i=1;i<total-n+1;i++){
//             temp= temp->next;
//         }
//         temp->next = temp->next->next;
        
//         return head->next;
//     }
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         ListNode *start = head;
//         int totalCount =1;
//         while(start->next != nullptr){
//             totalCount++;
//             start=start->next;
//         }
//         if(totalCount==1){
//             head= nullptr;
//             return head;
//         }
       
//         int pos = totalCount - n + 1;
        
//         // Change Head location
//         if(pos==1){
//             head = head->next;
//             return head;
//         }
//         ListNode *temp = head;
//         while(pos>2){
//             temp=temp->next;
//             pos--;
//         }
//         cout<<temp->val;
//         if(totalCount - n + 1 == totalCount){
//             temp->next = nullptr;
//             return head;
//         }
//         temp->next = temp->next->next;
//         return head;
//     }