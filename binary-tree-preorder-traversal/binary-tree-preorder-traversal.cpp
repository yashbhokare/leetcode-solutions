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
        // recursion(root,result);
        iteration(root,result);
        return result;
    }
    
    void recursion(TreeNode* root, vector<int>& result){
        if(root==NULL) return;
        result.push_back(root->val);
        recursion(root->left,result);
        recursion(root->right,result);
    }
    
    void iteration(TreeNode* root, vector<int>& result){
        if(root==NULL) return;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()){
            root=stk.top();
            stk.pop();
            result.push_back(root->val);
            if(root->right!=NULL){
                stk.push(root->right);
            }
            if(root->left!=NULL){
                stk.push(root->left);
            }
        }
    }
    
};