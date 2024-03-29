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
// class Solution {
// public:
    
//     int depth(TreeNode* root){
//         int depthValue = 0;
//         while(root->left){
//             root=root->left;
//             depthValue++;
//         }
//         return depthValue;
//     }
    
//      bool ifExists(TreeNode* node,int d,int index,int totalNodes){
//         int left = 0;
//         int right = totalNodes;// pow(2,d)-1;
        
//         while(d--){
//             int mid = left+(right-left)/2;
//             if(index<=mid){
//                 node=node->left;
//                 right=mid;
//             }else {
//                 node=node->right;
//                 left=mid+1;
//             }
//         }
//         return node==NULL? false : true;
//     }
    
//     int countNodes(TreeNode* root) {
//         if(root==NULL) return 0;
        
//         int d = depth(root);
//         if(d==0) return 1;
        
//         int totalNodes = pow(2,d)-1;
//         int left = 0;
//         int right = totalNodes;// pow(2,d)-1;
        
//         while(left<=right){
//             int mid = left+(right-left)/2;
//             if(ifExists(root,d,mid,totalNodes)){
//                 left = mid+1;
//             }else {
//                 right=mid-1;
//             }
//         }
//         int total = totalNodes + left;
//         return total;
        
//     }
    
   
// };

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        
        int l = 1, r = 1;
        TreeNode *ptr_r = root, *ptr_l = root;
        while (ptr_l = ptr_l->left) l++;
        while (ptr_r = ptr_r->right) r++;
        
        if (l == r) return pow(2, l) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};