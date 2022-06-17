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
    unordered_set<TreeNode*> covered;
    int ans=0;
    int minCameraCover(TreeNode* root) {
        covered.insert(NULL);
        dfs(root,NULL);
        return ans;
    }
    
    void dfs(TreeNode* node,TreeNode* par){
        if(node==NULL) return;
        
        dfs(node->left,node);
        dfs(node->right,node);
        
        if((par==NULL && covered.find(node)==covered.end()) || (covered.find(node->left)==covered.end() || covered.find(node->right)==covered.end())){
            ans++;
            covered.insert(par);
            covered.insert(node);
            covered.insert(node->left);
            covered.insert(node->right);
        } 
    }
};