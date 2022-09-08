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
    vector<int> result;
    vector<int> inorderTraversal(TreeNode* root) {
        // rec(root);
        inorderTraversalWithLoop(root);
        return result;
    }
    
    void rec(TreeNode* root){
        if(root==NULL) return;
        rec(root->left);
        result.push_back(root->val);
        rec(root->right);
    }
    
    void inorderTraversalWithLoop(TreeNode* root){
        
      stack<TreeNode*> stk;
       TreeNode* node =root;
        while(!stk.empty() || node){
            while(node){
                stk.push(node);
                node=node->left;
            }
            // if(node==NULL) stk.pop();
            if(!stk.empty() && stk.top()==NULL) break;
            
            TreeNode* currNode = stk.top();
            stk.pop();
            result.push_back(currNode->val);
            node = currNode->right;
        }
    }
};