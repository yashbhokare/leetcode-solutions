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
    TreeNode* result=NULL;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        lowestCommonAncestorCount(root,p,q);
        return result;
    }
    
    int lowestCommonAncestorCount(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL) return 0;
        
        int left = lowestCommonAncestorCount(root->left,p,q);
        int right = lowestCommonAncestorCount(root->right,p,q);
        int curr = root==p || root==q ? 1 : 0;
        
        int sum = left+right+curr;
        if(sum>1){
            result = root;
            sum=0;
        }
        
        return sum;
        
    }
};