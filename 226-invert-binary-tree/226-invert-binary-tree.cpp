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
    TreeNode* invertTree(TreeNode* root) {
        return rec(root);
    }
    
    TreeNode* rec(TreeNode* root){
        if(root==NULL) return NULL;
        
        TreeNode* tempRoot= new TreeNode(root->val);
        
        if(root->right!=NULL){
            tempRoot->left=rec(root->right);
        }
       
        if(root->left!=NULL){
            tempRoot->right = rec(root->left);
        }

        
        return tempRoot;
    }
};