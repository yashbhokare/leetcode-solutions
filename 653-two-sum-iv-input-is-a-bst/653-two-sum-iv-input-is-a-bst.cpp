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
    unordered_set<int> mapper;
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;
        int target  = k-root->val;
        if(mapper.find(target)!=mapper.end()) return true;
        mapper.insert(root->val);
        // cout<<root->val<<endl;
        return findTarget(root->left,k) || findTarget(root->right,k);
    }
    
};