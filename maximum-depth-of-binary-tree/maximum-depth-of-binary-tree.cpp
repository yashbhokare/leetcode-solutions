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
    int maxDepth(TreeNode* root) {
        return depthCal(root,0);
    }
    
    int depthCal(TreeNode* root,int depth){
        if(root==NULL){
            return depth;
        }
        int leftVal = depthCal(root->left,depth+1);
        int rightVal = depthCal(root->right,depth+1);
        return max(leftVal,rightVal);
    }
};