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
    TreeNode* prev;
    bool isValidBST(TreeNode* root) {
        return recValidBST(root);
    }
    
    bool recValidBST(TreeNode* root){
        if(root==NULL) return true;
        if(!recValidBST(root->left)) return false;
        
        if(prev && root->val<=prev->val){
            return false;
        }
        prev=root;
        return recValidBST(root->right);
    }
};