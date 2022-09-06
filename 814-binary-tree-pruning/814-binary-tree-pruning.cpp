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
    TreeNode* pruneTree(TreeNode* root) {
      
        TreeNode* dummyNode = new TreeNode();
        dummyNode->right = root;
        rec(dummyNode);
        return dummyNode->right;
    }
    
    int rec(TreeNode* root){
        if(root==NULL) return 0;
        
        if(root->left==NULL && root->right==NULL) return root->val;
        
        int leftVal = rec(root->left);
        int rightVal = rec(root->right);
        if(leftVal==0) root->left=NULL;
        if(rightVal==0) root->right=NULL;
        return leftVal || rightVal || root->val;
    }
};