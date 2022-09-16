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
    vector<TreeNode*> generateTrees(int n) {
        if(n==0) return {NULL};
        return generateTree(1,n);
        
    }
    
    vector<TreeNode*> generateTree(int start,int end){
        vector<TreeNode*> allTrees;
        if(start>end){
            allTrees.push_back(NULL);
            return allTrees;
        }

        for(int i=start;i<=end;i++){
            vector<TreeNode*> leftTree=generateTree(start,i-1);
            vector<TreeNode*> rightTree=generateTree(i+1,end);
            for(auto left:leftTree){
                for(auto right:rightTree){
                    TreeNode* newRoot = new TreeNode(i);
                    newRoot->left = left;
                    newRoot->right=right;
                    allTrees.push_back(newRoot);
                }
            }
        }
        return allTrees;
        
    }
    
};