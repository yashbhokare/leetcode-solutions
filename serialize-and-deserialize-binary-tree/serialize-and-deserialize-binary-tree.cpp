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
        if(root==NULL) return "NULL";
        return to_string(root->val)+" "+serialize(root->left)+" "+serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string word;
        return deserialize_string(ss);
    }
    
    TreeNode* deserialize_string(stringstream& ss) {
        string word;
        ss>>word;
        if(word=="NULL"){
            return NULL;
        }
        TreeNode* root = new TreeNode(stoi(word));
        root->left = deserialize_string(ss);
        root->right = deserialize_string(ss);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));