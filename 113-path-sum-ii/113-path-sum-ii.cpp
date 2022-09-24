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
    vector<vector<int>> result;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> total;
        rec(root,targetSum,total);
        return result;
    }
    
    void rec(TreeNode* root, int targetSum,vector<int>& total){
        if(root==NULL) return;
        targetSum-=root->val;
        total.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            if(targetSum==0){
                result.push_back(total);
            }
            total.pop_back();
            return;
        }
        rec(root->left,targetSum,total);
        rec(root->right,targetSum,total);
        total.pop_back();
        
        
    }
};