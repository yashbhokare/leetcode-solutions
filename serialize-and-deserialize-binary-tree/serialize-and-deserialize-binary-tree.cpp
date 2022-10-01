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
        if(root==NULL){
            return "NULL";
        }
        return to_string(root->val) + " "+serialize(root->left) +" "+ serialize(root->right);
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserialize_string(ss);
        return NULL;
    }
    
    TreeNode* deserialize_string(stringstream& ss){
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

// BFS with Queue
// class Codec:
//     '''       O(n) time and O(n) space, BFS traversal
//     e.g., 1
//          / \
//         2   5
//        / \
//       3   4  , level order traversal, serialize will be '1,2,5,3,4,None,None,None,None,None,None,'; deserialize 
//       with queue as well, convert back. Time and Space O(n).
//     '''
//     def serialize(self, root):
//         if not root:
//             return ''
//         queue = collections.deque()
//         queue.append(root)
//         res = ''
//         while queue:
//             node = queue.popleft()
//             if not node:
//                 res += 'None,'
//                 continue
//             res += str(node.val) + ','
//             queue.append(node.left)
//             queue.append(node.right)
//         return res
            
//     def deserialize(self, data):
//         if not data:
//             return None
//         ls = data.split(',')
//         root = TreeNode(int(ls[0]))
//         queue = collections.deque()
//         queue.append(root)
//         i = 1
//         while queue and i < len(ls):
//             node = queue.popleft()
//             if ls[i] != 'None':
//                 left = TreeNode(int(ls[i]))
//                 node.left = left
//                 queue.append(left)
//             i += 1
//             if ls[i] != 'None':
//                 right = TreeNode(int(ls[i]))
//                 node.right = right
//                 queue.append(right)
//             i += 1
//         return root