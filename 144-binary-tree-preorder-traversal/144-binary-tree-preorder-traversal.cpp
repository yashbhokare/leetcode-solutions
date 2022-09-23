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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        // preorderTraversalRec(root,result);
        preorderTraversalIterative(root,result);
        return result;
    }
    
    void preorderTraversalRec(TreeNode* root,vector<int>& result) {
        if(root==NULL) return ;
        result.push_back(root->val);
        preorderTraversalRec(root->left,result);
        preorderTraversalRec(root->right,result);
    }
    
    void preorderTraversalIterative(TreeNode* root,vector<int>& result) {
        if(root==NULL) return ;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()){
            TreeNode* node = stk.top();
            stk.pop();
            result.push_back(node->val);
            if(node->right) stk.push(node->right);
            if(node->left) stk.push(node->left);
        }
    }
};