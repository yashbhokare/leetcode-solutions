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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        return bfs(root);
    }
    
    vector<vector<int>> bfs(TreeNode* root){
        vector<vector<int>> result;
        
        map<int,vector<int>> mapper;
        
        queue<pair<TreeNode*,int>> q;
        
        if(root==NULL) return {};
        
        q.push({root,0});
        while(!q.empty()){
            int size = q.size();
            unordered_map<int,vector<int>> tempMapper;
            while(size--){
                int index = q.front().second;
                TreeNode* node = q.front().first;
                tempMapper[index].push_back(node->val);
                q.pop();
                if(node->left) q.push({node->left,index-1});
                if(node->right) q.push({node->right,index+1});
            }
            for(auto it=tempMapper.begin();it!=tempMapper.end();it++){
                vector<int> values= it->second;
                int newIndex = it->first;
                if(values.size()>1) sort(values.begin(),values.end());
                mapper[newIndex].insert(mapper[newIndex].end(),values.begin(),values.end());
            }
           
        }
        
        for(auto it=mapper.begin();it!=mapper.end();it++){
            result.push_back(it->second);
        }
        return result;
        
    }
};