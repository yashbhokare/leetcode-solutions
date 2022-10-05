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
    int max_result = INT_MIN;
    int maxPathSum(TreeNode* root) {
        maxPath(root);
        return max_result;
    }
    
    int maxPath(TreeNode* root){
        if(root==NULL) return 0;
        int left = max(maxPath(root->left),0);
        int right =  max(maxPath(root->right),0);
        int sum = left + right + root->val;
        max_result = max(sum,max_result);
        return max(left,right)+root->val;
    }
};