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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return isSameTree_Iterative(p,q);
        // return isSameTree_Recursion(p,q);
    }
    
    bool isSameTree_Recursion(TreeNode* p, TreeNode* q) {
        return isSameTree_Iterative(p,q);
        if(p==NULL && q==NULL) return true;
        if(p==NULL || q==NULL || p->val!=q->val) return false;
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
    
    bool isSameTree_Iterative(TreeNode* a, TreeNode* b){
        queue<TreeNode*> q;
        q.push(a);
        q.push(b);
        while(!q.empty()){
            TreeNode* temp1 = q.empty() ? NULL : q.front(); q.pop();
            TreeNode* temp2 = q.empty() ? NULL : q.front(); q.pop();
            if(temp1==NULL && temp2==NULL) continue;
            if(temp1==NULL || temp2==NULL || temp1->val!=temp2->val) return false;
            q.push(temp1->left);
            q.push(temp2->left);
            q.push(temp1->right);
            q.push(temp2->right);

        }
        return true;
    }
};