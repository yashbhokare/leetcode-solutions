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
    bool result= true;
    bool isBalanced(TreeNode* root) {
        depth(root);
        return result;
    }
    
    int depth(TreeNode* root){
        if(root==NULL) return 0;
        
        int leftDepth = depth(root->left);
        int rightDepth = depth(root->right);
        
        if(abs(rightDepth-leftDepth)>1){
            result = false;
        }
        return max(leftDepth,rightDepth)+1;
    }
};