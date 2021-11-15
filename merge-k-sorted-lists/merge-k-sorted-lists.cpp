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
        ListNode* temp = new ListNode(0);
        ListNode* head = temp;
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;
        for(auto list: lists){
            if(list){
                 pq.push({list->val,list});
            }
           
        }
        
        while(!pq.empty()){
            int value = pq.top().first;
            ListNode* node = pq.top().second;
            temp->next = new ListNode(value);
            temp = temp->next;
            pq.pop();
            if(node->next){
                node=node->next;
                pq.push({node->val,node});
            }
        }
        
        return head->next;
    }
};



// class Solution {
// public:
//     ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
//         if (!l1) return l2;
//         if (!l2) return l1;
//         ListNode* head = l1->val <= l2->val? l1 : l2;
//         head->next = l1->val <= l2->val ? merge2Lists(l1->next, l2) : merge2Lists(l1, l2->next);
//         return head;
//     }
    
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         if (lists.size() == 0) return NULL;
//         ListNode* head = lists[0];
//         for (int i = 1; i < lists.size(); i++)
//             head = merge2Lists(head, lists[i]);
        
//         return head;
//     }
// };

// class Solution {
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         // Create an ordered map
//         map<int, int> nodes;
        

//         // Add all nodes of all the LinkedLists to the map with
//         // with the ListNode->val as the key & that value's frequency as the mapped value
//         for(int i = 0; i < lists.size(); ++i){
//             auto node = lists[i];
//             while(node){
//                 int temp = node->val;
//                 nodes[temp]++;
//                 node = node->next;
//             }
//         }
        
//         ListNode dummyHead(0);
//         ListNode* tail = &dummyHead;
        
//         for(auto it: nodes){
//             while(it.second != 0){
//                 ListNode* newNode= new ListNode(it.first);
//                 tail->next = newNode;
//                 tail = tail->next;
//                 it.second--;
//             }
//         }
//         return dummyHead.next;
//     }
// };