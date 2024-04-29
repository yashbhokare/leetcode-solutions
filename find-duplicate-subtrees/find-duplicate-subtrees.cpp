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
    vector<TreeNode*> result;
    unordered_map<string,int> mapper;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return result;
    }
    
    string dfs(TreeNode* root){
        if(root==NULL) return "";
        string val=to_string(root->val)+","+dfs(root->left)+","+dfs(root->right);
        mapper[val]++;
        if(mapper[val]==2)
            result.push_back(root);
        return val;
    }
};