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
    bool isSymmetric(TreeNode* root) {
        return isSymmetric_Iterative(root->left,root->right);
    }
    
    bool isSymmetric_Rec(TreeNode* left,TreeNode* right)
    {
        if(left==NULL && right == NULL) return true;
        if(left==NULL || right==NULL || left->val!=right->val) return false;
        return isSymmetric_Rec(left->right,right->left) && isSymmetric_Rec(left->left,right->right);
    }
    
    bool isSymmetric_Iterative(TreeNode* l,TreeNode* r)
    {
        queue<TreeNode*> q;
        q.push(l);
        q.push(r);
        while(!q.empty()){
            TreeNode* left = q.front();q.pop();
            TreeNode* right = q.front();q.pop();
            if(left==NULL && right==NULL) continue;
            if(left==NULL || right==NULL || left->val!=right->val) return false;
            q.push(left->left);
            q.push(right->right);
            q.push(left->right);
            q.push(right->left);
        }
        return true;
    }
};