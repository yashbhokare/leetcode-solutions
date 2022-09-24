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
    int maxValue = INT_MIN;
    int maxPathSum(TreeNode* root) {
        rec(root);
        return maxValue;
    }
    
    int rec(TreeNode* root){
        if(root==NULL) return 0;
        int leftSubtree = max(rec(root->left),0);
        int rightSubtree = max(rec(root->right),0);
        int sum = leftSubtree+rightSubtree+root->val;
        maxValue = max(sum,maxValue);
        return max(leftSubtree,rightSubtree)+root->val;
    }
};