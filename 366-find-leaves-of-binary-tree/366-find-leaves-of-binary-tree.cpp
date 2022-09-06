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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> result;
        int count = 3;
        while(root->left || root->right){
            vector<int> leaves;
            rec(root,leaves);
            result.push_back(leaves);
        }
        result.push_back({root->val});
        return result;
    }
    
    TreeNode* rec(TreeNode* root,vector<int>& leaves){
        if(root==NULL) return NULL;
        if(root->left==NULL && root->right==NULL){
            leaves.push_back(root->val);
            return NULL;
        }
        root->left = rec(root->left,leaves);
        root->right = rec(root->right,leaves);
        return root;
    }
    
    void print(TreeNode* root){
        if(root==NULL) return;
        cout<<root->val<<"->";
        print(root->left);
        print(root->right);
    }
    
};