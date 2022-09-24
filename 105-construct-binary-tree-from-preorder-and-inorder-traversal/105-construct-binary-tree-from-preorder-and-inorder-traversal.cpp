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
    int index=0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return rec(preorder,inorder);
    }
    
    TreeNode* rec(vector<int>& preorder, vector<int> inorder){
        if(inorder.size()==0) return nullptr;
        
        int rootVal = preorder[index++];
        
        int inorderIndex = find(inorder.begin(),inorder.end(),rootVal)-inorder.begin();
        
        TreeNode* root = new TreeNode(rootVal);
        root->left = rec(preorder,{inorder.begin(),inorder.end()-(inorder.size()-inorderIndex)});
        root->right = rec(preorder,{inorder.begin()+inorderIndex+1,inorder.end()});
        return root;
        
    }
};