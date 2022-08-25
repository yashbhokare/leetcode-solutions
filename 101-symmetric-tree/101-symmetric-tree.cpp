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
        if(root ==NULL) return NULL;
        return isSymmetricCal(root->left,root->right);
    }
    bool isSymmetricCal(TreeNode* left, TreeNode* right){
        if(left==NULL && right==NULL) return true;
        if(left==NULL || right==NULL) return false;
        if(left->val == right->val){
            return isSymmetricCal(left->right,right->left) && isSymmetricCal(left->left,right->right);
        }else {
            return false;
        }
    }
};