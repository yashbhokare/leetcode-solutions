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
//https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/discuss/1415153/Conversion-using-Doubling-method-(Explanation-+-code)
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        
        int result = 0;
        int prev = 0;
        while(head!=NULL){
            prev = prev*2 + head->val;
            head=head->next;
        }
        return prev;
        return convertBinaryToDecimal(result);
    }
    
    int convertBinaryToDecimal(long long int n){
        int base = 1;
        int result = 0;
        while(n){
            int number = n%10;
            int cal = number*base;
            result = result + cal;
            n = n/10;
            base = base*2;
        }
        return result;
    }
};