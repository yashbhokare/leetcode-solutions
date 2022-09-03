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
        ListNode* root = new ListNode();
        ListNode* curr = root;
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> minHeap;
        
        for(auto list:lists){
            if(list){
                minHeap.push({list->val,list});
            }
        }
        
        while(!minHeap.empty()){
            ListNode* temp = minHeap.top().second;
            minHeap.pop();
            curr->next = temp;
            if(temp->next){
                minHeap.push({temp->next->val,temp->next});
                temp->next=NULL;
            }
            curr=curr->next;
            
        }
        return root->next;
        
    }
};