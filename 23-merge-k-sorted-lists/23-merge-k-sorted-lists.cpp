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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode(0);
        ListNode* res = head;
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> minHeap;
        for(auto list:lists){
            if(list!=NULL){
                minHeap.push({list->val,list});
            }
        }
        
        while(!minHeap.empty()){
            ListNode* temp = minHeap.top().second;
            minHeap.pop();
            res->next = temp;
            if(temp->next!= NULL){
                minHeap.push({temp->next->val,temp->next});
            }
            res=res->next;
        }
        
        return head->next;
    }
};