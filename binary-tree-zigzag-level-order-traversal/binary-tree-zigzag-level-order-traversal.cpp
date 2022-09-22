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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return {};
        
        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);
        bool isZigZag=false;
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            while(size--){
                TreeNode* temp = q.front();
                q.pop();
                if(isZigZag){
                    level.insert(level.begin(),temp->val);
                }else {
                    level.push_back(temp->val);
                }
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            result.push_back(level);
            isZigZag = !isZigZag;
        }
        return result;
    }
};