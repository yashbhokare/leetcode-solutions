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
    int result = 0;
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_set<int> numset;
        int distinctElement = 0;
        recursion(root,numset,distinctElement);
        return result;
    }
    
    
    
    void recursion(TreeNode* root,unordered_set<int>& numset,int distinctElement){
        if(root==NULL){
            return;
        }
        
        int currDistinctElement = distinctElement;
        bool isRemoved = false;
        
        if(numset.find(root->val)!=numset.end()){
            distinctElement--;
            numset.erase(root->val);
            isRemoved = true;
        }else {
            distinctElement++;
            numset.insert(root->val);
            isRemoved = false;
        }
        
        // Check only for leaf nodes
        if(root->left==NULL && root->right==NULL){
            if(distinctElement==0 || distinctElement==1){
                result++;
            }
             if(isRemoved){
                numset.insert(root->val);
            }else {
                numset.erase(root->val);
            }
            return;
        }
        
        recursion(root->left,numset,distinctElement);
        recursion(root->right,numset,distinctElement);
        
        if(isRemoved){
            numset.insert(root->val);
        }else {
            numset.erase(root->val);
        }
        
        
    }
};