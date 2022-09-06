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
    int maxResult = INT_MIN;
    int maxPathSum(TreeNode* root) {
        rec(root);
        return maxResult;
    }
    
    int rec(TreeNode* root){
        if(root==NULL) return 0;
        int leftValue = max(0,rec(root->left));
        int rightValue = max(0,rec(root->right));
        int sum = leftValue + rightValue + root->val;
        maxResult = max(maxResult,sum);
        return max(leftValue,rightValue)+root->val;
    }
};