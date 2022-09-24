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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return rec(inorder,postorder);
    }
    
    TreeNode* rec(vector<int> inorder,vector<int>& postorder){

        if(inorder.size()==0) return nullptr;
        
        int rootValue = postorder.back(); postorder.pop_back();

        TreeNode* root = new TreeNode(rootValue);

        int inorderIndex = find(inorder.begin(),inorder.end(),rootValue)-inorder.begin();
        
        root->right = rec({inorder.begin()+inorderIndex+1,inorder.end()},postorder);
        
        root->left = rec({inorder.begin(),inorder.end()-(inorder.size()-inorderIndex)},postorder);
        return root;
    }
};