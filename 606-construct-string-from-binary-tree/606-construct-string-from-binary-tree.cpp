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
    string tree2str(TreeNode* root) {
        string result="";
        rec(root,result);
        return result;
    }
    
    void rec(TreeNode* root, string& s){
        if(root==NULL){
            // s.pop_back();
            return;
        }
        if(root->left==NULL && root->right==NULL){
            s+=to_string(root->val);
            return;
        }
        s+=to_string(root->val)+"(";
        rec(root->left,s);
        s+=")";
        
        if(root->right){
             s+="(";
            rec(root->right,s);
            s+=")";
        }
       

        
    }
};