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
    int result = 1;
    int longestConsecutive(TreeNode* root) {
        rec(root,1);
        return result;
    }
    
    void rec(TreeNode* root, int total){
        // cout<<total;
        result = max(result,total);
        if(root==NULL) return;
        if(root->left){
            if(root->left->val==root->val+1) rec(root->left,total+1);
            else rec(root->left,1);
        }
        if(root->right){
            // cout<<root->right->val<<" "<<root->val+1<<endl;
            if(root->right->val==root->val+1) rec(root->right,total+1);
             else rec(root->right,1);
        }
        
        
    }
};