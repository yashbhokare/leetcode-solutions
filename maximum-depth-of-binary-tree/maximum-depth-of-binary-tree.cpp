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
        return topDown(root,0);
    }
    
    int topDown(TreeNode* root, int depth){
        if(root==NULL) return depth;
        int leftVal=topDown(root->left,depth+1);
        int rifghtVal=topDown(root->right,depth+1);
        return max(leftVal,rifghtVal);
    }
};