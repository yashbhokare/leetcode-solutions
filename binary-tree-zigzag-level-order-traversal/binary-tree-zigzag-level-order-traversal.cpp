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
        deque<TreeNode*> dq;
        dq.push_back(root);
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
                    auto it = level.begin();
                    level.insert(it,current->val);
                }
                
                if(current->left !=NULL){
                    dq.push_back(current->left);
                }
                if(current->right !=NULL){
                    dq.push_back(current->right);
                }
                dq.pop_front();
            }
            zigzag = !zigzag;
            result.push_back(level);
        }
        return result;
    }
};