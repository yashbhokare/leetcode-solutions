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
    vector<TreeNode*> nodes;
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
         if(root==NULL) return false;
        
        int subRootDepth = depth(subRoot,-1);
        depth(root,subRootDepth);
        for(auto node:nodes){
            if(isEqual(node,subRoot)) return true;
        }
        return false;
        // if(isEqual(root,subRoot)) return true;
        // return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
    
    bool isEqual(TreeNode* p, TreeNode* q){
        if(p==NULL && q==NULL) return true;
        if(p==NULL || q==NULL || p->val!=q->val) return false;
        return isEqual(p->left,q->left) && isEqual(p->right,q->right);
    }
    
    int depth(TreeNode* root, int d){
        if(root==NULL) return 0;
        int left = depth(root->left,d);
        int right = depth(root->right,d);
        int maxDepth = max(left,right)+1;
        if(maxDepth==d) nodes.push_back(root);
        return maxDepth;
    }
};