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
    bool result= false;
    bool hasPathSum(TreeNode* root, int targetSum) {
        return checkPathSum(root,targetSum);
    }
    
    bool checkPathSum(TreeNode* root, int targetSum){
        if(root==NULL) return false;
        targetSum = targetSum - root->val;
        if(root->left==NULL && root->right==NULL){
            return targetSum==0;
        }
        return checkPathSum(root->left,targetSum) || checkPathSum(root->right,targetSum);
        
    }
};