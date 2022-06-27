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
    int result = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        rec(root);
        return result;
    }
    
    int rec(TreeNode* root){
        if(root==NULL) return 0;
        
        int leftDepth = rec(root->left);
        int rightDepth = rec(root->right);
        
        int sum = leftDepth + rightDepth;
        result = max(result,sum);
        return max(leftDepth,rightDepth)+1;
    }
};