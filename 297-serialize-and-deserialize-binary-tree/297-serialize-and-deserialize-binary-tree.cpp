/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root){
            return "NULL,";
        }
        
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserialize_helper(ss);
    }
    
    TreeNode* deserialize_helper(stringstream& ss){
        string curr;
        getline(ss, curr, ',');
        
        if(curr == "NULL"){
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(stoi(curr));
        root->left = deserialize_helper(ss);
        root->right = deserialize_helper(ss);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));