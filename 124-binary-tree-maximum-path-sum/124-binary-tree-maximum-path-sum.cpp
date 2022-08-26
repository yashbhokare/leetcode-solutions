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
    int res = INT_MIN;
    int maxPathSum(TreeNode* root) {
        int val = rec(root);
        return max(res,val);
    }
    
    int rec(TreeNode* root){
        if(root==NULL) return 0;
        int leftD = max(rec(root->left),0);
        int rightD = max(rec(root->right),0);
        int total = leftD+rightD+root->val;
        res = max(res,total);
        return max(leftD,rightD)+root->val;
    }
};