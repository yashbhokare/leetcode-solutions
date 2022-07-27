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
    TreeNode* tempRoot = new TreeNode(0);
    void flatten(TreeNode* root) {
        preorder(root);
    }
    
    void preorder(TreeNode* root){
        if(root==NULL) return;
        tempRoot->right = root;
        tempRoot->left = NULL;
        tempRoot = tempRoot->right;
        TreeNode* rightRoot=root->right;
        preorder(root->left);
        preorder(rightRoot);
    }
};