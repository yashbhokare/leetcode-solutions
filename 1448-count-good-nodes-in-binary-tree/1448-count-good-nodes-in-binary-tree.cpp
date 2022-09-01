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
    int ans = 0;
    int goodNodes(TreeNode* root) {
        rec(root,root->val);
        return ans;
    }
    
    void rec(TreeNode* root, int max){
        if(root==NULL) return;
        if(root->val>=max){
            max = root->val;
            ans++;
        }
        rec(root->left,max);
        rec(root->right,max);
    }
};