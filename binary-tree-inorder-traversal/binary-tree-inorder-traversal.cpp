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
        // recursion(root,result);
        iterative(root,result);
        return result;
    }
    
    void recursion(TreeNode* root, vector<int>& result){
        if(root==NULL) return;
        recursion(root->left,result);
        result.push_back(root->val);
        recursion(root->right,result);
    }
    
    void iterative(TreeNode* root, vector<int>& result){
        if(root==NULL) return;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()){
            while(root!=NULL && root->left!=NULL){
                stk.push(root->left);
                root=root->left;
            }
            TreeNode* top=stk.top();
            // cout<<top->val;
            stk.pop();
            
            result.push_back(top->val);
            if(top->right!=NULL) stk.push(top->right);
            root=top->right;
        }
    }
};