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
    vector<int> result;
    vector<int> inorderTraversal(TreeNode* root) {
        // rec(root);
        inorderTraversalWithLoop(root);
        return result;
    }
    
    void rec(TreeNode* root){
        if(root==NULL) return;
        rec(root->left);
        result.push_back(root->val);
        rec(root->right);
    }
    
    void inorderTraversalWithLoop(TreeNode* root){
        if(root==NULL) return;
        stack<TreeNode*> stk;
        while(!stk.empty() || root){
            while(root){
                stk.push(root);
                root=root->left;
            }
            TreeNode* temp = stk.top();
            stk.pop();
            result.push_back(temp->val);
            root=temp->right;
        }
 

    }

};