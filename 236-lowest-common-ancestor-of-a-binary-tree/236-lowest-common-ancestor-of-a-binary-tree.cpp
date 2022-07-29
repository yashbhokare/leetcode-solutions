/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* result;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        recursion(root,p,q);
        return result;
    }
    
    bool recursion(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL) return false;
        
        bool leftTree = recursion(root->left,p,q);
        bool rightTree = recursion(root->right,p,q);
        
        if((leftTree && rightTree) || ((leftTree || rightTree) && ((root==p) || (root==q)))){
            result = root;
            return false;
        }
        
        if((root==p) || (root==q)) return true;
        
        if(leftTree || rightTree) return true;
        
        return false;
    }
};