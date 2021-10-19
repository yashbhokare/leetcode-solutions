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
    int prevNode = -50;
    bool result = true;
    bool isValidBST(TreeNode* root) {
        rec(root);
        return result;
    }
    
    void rec(TreeNode* root){
        if(root==NULL){
            return;
        }
        
        rec(root->left);
        if(prevNode!=-50 && root->val <= prevNode){
            result = false;
            return;
        }
        prevNode = root->val;
        rec(root->right);
        
    }
};