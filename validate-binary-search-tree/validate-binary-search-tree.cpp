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
    bool ans = true;
    TreeNode* prev = NULL;
    bool isValidBST(TreeNode* root) {

        isValidBSTCal(root);
        return ans;
    }
    
    void isValidBSTCal(TreeNode* root) {
        if(root == NULL)
            return;
        isValidBSTCal(root->left);
        if(prev!=NULL && root->val <= prev->val){
            ans = false;
        }
       
        prev = root;
        isValidBSTCal(root->right);
    }
};