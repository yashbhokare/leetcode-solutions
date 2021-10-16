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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorderTraverseUsingStack(root,result);
        return result;
    }
    
    void inorderTraverse(TreeNode* root,vector<int>& result){
        if(root == NULL){
            return;
        }
        inorderTraverse(root->left,result);
        result.push_back(root->val);
        inorderTraverse(root->right,result);
        
    }
    
    void inorderTraverseUsingStack(TreeNode* root,vector<int>& result){
        
        stack<TreeNode*> stackVal;
        TreeNode* cur = root;
        while(cur!=NULL || !stackVal.empty()){
            while(cur!=NULL){
                stackVal.push(cur);
                cur= cur->left;
            }
            TreeNode* temp = stackVal.top();
            stackVal.pop();
            result.push_back(temp->val);
            cur = temp->right;
        }
    }
    
};