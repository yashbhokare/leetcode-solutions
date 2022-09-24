/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    priority_queue<int> maxHeap;
    int kthSmallest(TreeNode* root, int k) {
        return inorderUsingStack(root,k);
        // rec(root,k);
        // return maxHeap.top();
    }
    
    void rec(TreeNode* root, int k){
        if(root==NULL) return;
        maxHeap.push(root->val);
        if(maxHeap.size()>k)  maxHeap.pop();
        rec(root->left,k);
        rec(root->right,k);
    }
    
    int inorderUsingStack(TreeNode* root, int k){
        stack<TreeNode*> stk;
        while(!stk.empty() || root){
            while(root){
                stk.push(root);
                root=root->left;
            }
            TreeNode* temp = stk.top();
            stk.pop();
            if(--k==0) return temp->val;
            root=temp->right;
        }
        return -1;
    }
};