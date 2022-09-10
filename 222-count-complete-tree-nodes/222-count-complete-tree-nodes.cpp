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
    
    int depth(TreeNode* root){
        int depthValue = 0;
        while(root->left){
            root=root->left;
            depthValue++;
        }
        return depthValue;
    }
    
     bool ifExists(TreeNode* root,int d,int index){
        TreeNode* node = root;
        int left = 0;
        int right = pow(2,d)-1;
        
        while(d--){
            int mid = left+(right-left)/2;
            if(index<=mid){
                node=node->left;
                right=mid;
            }else {
                node=node->right;
                left=mid+1;
            }
        }
        return node==NULL? false : true;
    }
    
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        
        int d = depth(root);
        if(d==0) return 1;
        
        int left = 0;
        int right = pow(2,d)-1;
        
        while(left<=right){
            int mid = left+(right-left)/2;
            if(ifExists(root,d,mid)){
                left = mid+1;
            }else {
                right=mid-1;
            }
        }
        int total = pow(2,d)-1 + left;
        return total;
        
    }
    
   
};