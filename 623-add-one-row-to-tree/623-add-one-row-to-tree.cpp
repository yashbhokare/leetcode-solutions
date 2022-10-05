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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        return bfs(root,val,depth);
    }
    
     TreeNode* bfs(TreeNode* root, int val, int depth){
         if(depth==1) {
             TreeNode* new_root = new TreeNode(val);
             new_root->left = root;
             return new_root;
         }
         
         int currDepth=1;
         queue<TreeNode*> q;
         q.push(root);
         while(!q.empty()){
             int size = q.size();
             if((currDepth)==(depth-1)) break;
             while(size--){
                 TreeNode* node = q.front();
                 q.pop();
                 if(node->left) q.push(node->left);
                 if(node->right) q.push(node->right);
             }
             
             currDepth++;
             // cout<<currDepth<<endl;
             if((currDepth)==(depth-1)) break;
         }
         TreeNode* left;
         TreeNode* right;
         while(!q.empty()){
            TreeNode* node = q.front();
            // if(node->left){
                left = node->left;
                TreeNode* new_left_node = new TreeNode(val);
                new_left_node->left = left;
                node->left = new_left_node;
            // }
            // if(node->right){
                right = node->right;
                TreeNode* new_right_node = new TreeNode(val);
                new_right_node->right = right;
                node->right = new_right_node;
            // }
            q.pop();
         }
         return root;
     }
};