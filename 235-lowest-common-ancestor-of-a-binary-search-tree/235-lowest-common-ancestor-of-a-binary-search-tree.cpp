/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* P;
    TreeNode* Q;
    TreeNode* result;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        P=p;
        Q=q;
        return rec(root);
        // rec(root);
        // return result;
    }
    
//     bool rec(TreeNode* root){
//         if(root==NULL) return false;
        
        
//         bool leftRes = rec(root->left);
//         bool rightRes= rec(root->right);
        
//         if(root==P && (leftRes || rightRes)){
//             result = root;
//             return false;
//         }else if(root==Q && (leftRes || rightRes)){
//             result = root;
//             return false;
//         }
            
//         if(root==P || root==Q) return true;
        
//         if(leftRes && rightRes) {
//             result = root;
//             cout<<result->val;
//         }else {
//             return leftRes || rightRes;
//         }
//         return false;
//     }
    
     TreeNode* rec(TreeNode* root){
         if(P->val < root->val && Q->val < root->val){
             return rec(root->left);
         }else if(P->val > root->val && Q->val > root->val){
             return rec(root->right);
         }else {
             return root;
         }
     }
};