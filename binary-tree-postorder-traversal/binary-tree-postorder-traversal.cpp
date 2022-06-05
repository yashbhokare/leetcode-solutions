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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        // postorderTravere(root,result);
        postorderTraversalWithStack(root,result);
        return result;
    }
    
    void postorderTravere(TreeNode* root,vector<int>& result){
        if(root == NULL){
            return;
        }
        postorderTravere(root->left,result);
        postorderTravere(root->right,result);
        result.push_back(root->val);
        
    }
    
      vector<int> postorderTraversalWithStack(TreeNode* root,vector<int>& ans) {
        stack<TreeNode*> stk;
        if(root)stk.push(root);
        while(stk.size())
        {
            auto p = stk.top();
            //All children nodes are visited
            if(p == nullptr)
            {
                stk.pop();
                ans.push_back(stk.top()->val);
                stk.pop();
                continue;
            }
            //Use nullptr to mark parent node
            stk.push(nullptr);
            //last in first out
            if(p->right)stk.push(p->right);
            if(p->left)stk.push(p->left);
        }
        return ans;
    }
};