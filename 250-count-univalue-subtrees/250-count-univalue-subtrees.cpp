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
    int count=0;
    int countUnivalSubtrees(TreeNode* root) {
        rec(root);
        return count;
    }
    
    bool rec(TreeNode* root){
        if(root==NULL) return true;
        
        if(root->left==NULL && root->right==NULL){
            count++;
            return true;
        }
       
        bool leftTree = rec(root->left);
        bool rightTree = rec(root->right);
        
        if(leftTree && rightTree){
             if(root->left && root->right && root->left->val==root->val && root->right->val==root->val){
                count++;
                return true;
            }else if(root->left && root->right==NULL && root->left->val==root->val){
                count++;
                  return true;
            }else if(root->right && root->left==NULL && root->right->val==root->val){
                count++;
                 return true;
            }else {
                 return false;
             }
            
        }else {
            return false;
        }
       
    }
};