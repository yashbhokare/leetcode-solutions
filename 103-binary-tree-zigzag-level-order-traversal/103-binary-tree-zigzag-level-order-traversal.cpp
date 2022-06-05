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
        if(root == NULL) return {};
        queue<TreeNode*> dq;
        dq.push(root);
        vector<vector<int>> result;
        bool zigzag = true;
        while(!dq.empty()){
            
            int size = dq.size();
            vector<int> level = {};

            for(int i=0;i<size;i++){
                TreeNode* current = dq.front();
                if(zigzag) {
                    level.push_back(current->val);
                }
                else {
                    level.insert(level.begin(),current->val);
                }
                
                if(current->left !=NULL){
                    dq.push(current->left);
                }
                if(current->right !=NULL){
                    dq.push(current->right);
                }
                dq.pop();
            }
            zigzag = !zigzag;
            result.push_back(level);
        }
        return result;
    }
};