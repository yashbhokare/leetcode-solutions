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
        rec(root,p,q);
        return result;
    }
    
    bool rec(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL) return false;
        
        bool leftTree = rec(root->left,p,q);
        bool rightTree = rec(root->right,p,q);
        
        if((leftTree && rightTree) || ((rightTree ||leftTree) && (root==p || root==q))) {
            result = root;
            return true;
        }
        
        if(root==p || root==q ) return true;
        
        if(leftTree || rightTree) return true;
        
        return false;
        
    }
};