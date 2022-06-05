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
        if(root==NULL) return result;
        // preorderTraversal(root, result);
        preorderWithoutRecursion(root,result);
        return result; 
    }
    
    void preorderTraversal(TreeNode* root,vector<int> &result){
        if(root==NULL) return;
        result.push_back(root->val);
        preorderTraversal(root->left,result);
        preorderTraversal(root->right,result);
    }
    
    void preorderWithoutRecursion(TreeNode* root,vector<int> &result){
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()){
            TreeNode* node = stk.top();
            stk.pop();
            result.push_back(node->val);
            if(node->right!=NULL){
                stk.push(node->right);
            }
            if(node->left!=NULL){
                stk.push(node->left);
            }
        }
    }
};