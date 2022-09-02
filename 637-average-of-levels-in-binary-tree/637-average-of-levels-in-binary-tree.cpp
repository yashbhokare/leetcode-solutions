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
    vector<double> averageOfLevels(TreeNode* root) {
        return bfs(root);
    }
    
    vector<double> bfs(TreeNode* root){
        if(root==NULL) return {};
        
        vector<double> result;
        queue<TreeNode*> q;
        q.push(root);
        // cout<<q.front()->val;
        while(!q.empty()){
            int size = q.size();
            double total = q.size();
            double sum = 0;
            while(size--){
                TreeNode* temp = q.front();
                // cout<<temp->val;
                sum = sum + temp->val;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                q.pop();
            }
            
            double avg = sum/total;
            result.push_back(avg);
        }
        return result;
        
    }
    
};