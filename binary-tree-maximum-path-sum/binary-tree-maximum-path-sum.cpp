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
    int ans = INT_MIN;
    int maxPathSum(TreeNode* root) {
        rec(root);
        return ans;
    }
    
    int rec(TreeNode* root){
        if(root==NULL){
            return 0; 
        }
        int leftVal = max(rec(root->left),0);
        int rightVal = max(rec(root->right),0);
        int total = leftVal+rightVal+root->val;
        ans= max(ans,total);
        return root->val + max(leftVal,rightVal);
    }
};