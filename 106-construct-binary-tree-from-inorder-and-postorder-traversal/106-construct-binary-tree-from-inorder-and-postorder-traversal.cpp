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
//         int rootValue = postorder.back();
        
//         int inOrderIndex = find(inorder.begin(),inorder.end(),rootValue)-inorder.begin();
        
        
//         TreeNode* root = new TreeNode(rootValue);
//         postorder.pop_back();
//         root->right = rec({inorder.begin()+inOrderIndex+1,inorder.end()},postorder);
//         root->left = rec({inorder.begin(),inorder.begin()+inOrderIndex-1},postorder);
        return rec(inorder,postorder);
    }
    
    TreeNode* rec(vector<int> inorder,vector<int>& postorder){
        // for(auto in:inorder) cout<<in<<" ";
        // cout<<endl;
        if(inorder.size()==0) return nullptr;
        
        int rootValue = postorder.back(); postorder.pop_back();
        // cout<<rootValue<<endl;
        TreeNode* root = new TreeNode(rootValue);
        
        if(inorder.size()==1){
             root->left=nullptr;
             root->right=nullptr;
            return root;
        }
        
        int inorderIndex = find(inorder.begin(),inorder.end(),rootValue)-inorder.begin();
        root->right = rec({inorder.begin()+inorderIndex+1,inorder.end()},postorder);
        root->left = rec({inorder.begin(),inorder.end()-(inorder.size()-inorderIndex)},postorder);
        return root;
    }
};