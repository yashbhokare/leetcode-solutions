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
    int maximum =0;
    int diameterOfBinaryTree(TreeNode* root) {
        rec(root);
        return maximum;
    }
    
    int rec(TreeNode* root){
        if(root==NULL) return 0;
        int leftValue = rec(root->left);
        int rightValue = rec(root->right);
        maximum = max(maximum,leftValue+rightValue);
        return max(leftValue,rightValue)+1;
    }
};