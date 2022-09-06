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
    unordered_map<int,TreeNode*> parentMapper;
    TreeNode* startNode;
    TreeNode* lcaNode;
    string getDirections(TreeNode* root, int startValue, int destValue) {
        lca(root,startValue,destValue);
        string s1 = "", s2 = "";
        path(lcaNode,startValue,s1);
        path(lcaNode,destValue,s2);
        for(auto &v:s1){
            v= 'U';
        }
        return s1+s2;
        // return "";
    }

    
    void traverse(TreeNode* root, int target, string s, string& result){
            if(root==NULL) return;
            if(result.size()!=0) return;
            if(root->val==target && result=="") {
                result = s;
                return;
            }
            
            if(root->left){
                s.push_back('L');
                traverse(root->left,target,s,result);
                s.pop_back();
            }
            if(root->right){
                s.push_back('R');
                traverse(root->right,target,s,result);
                s.pop_back();
            }
        
    }
    int path(TreeNode* root,int& t,string& p){
        if(!root) return 0;
        if(root->val==t) return 1;
        if(root->left){
            p+="L";
            if(path(root->left,t,p)) return 1;
            p.pop_back();
        }
        if(root->right){
            p+="R";
            if(path(root->right,t,p)) return 1;
            p.pop_back();
        }
        return 0;
    } 
    
    
    bool lca(TreeNode* root, int p, int q){
        if(root==NULL) return false;
        
        bool leftTree = lca(root->left,p,q);
        bool rightTree = lca(root->right,p,q);
        
        if((leftTree && rightTree) || ((leftTree || rightTree) && ((root->val==p) || (root->val==q)))){
            lcaNode = root;
            return false;
        }
        
        if((root->val==p) || (root->val==q)) return true;
        
        if(leftTree || rightTree) return true;
        
        return false;
    }
};
    
    
//          rec(root,NULL,startValue);
        
//         queue<pair<TreeNode*,string>> q;
//         unordered_set<int> visited;
//         q.push({startNode,""});
//         visited.insert(startNode->val);
//         while(!q.empty()){
//             int size = q.size();
//             while(size--){
//                 TreeNode* currNode = q.front().first;
//                 string currString = q.front().second;
                
//                 if(currNode->val==destValue) return currString;
//                 q.pop();
//                 if(currNode->left && visited.find(currNode->left->val)==visited.end()){
//                     q.push({currNode->left,currString+'L'});
//                     visited.insert(currNode->left->val);
//                 }
//                 if(currNode->right && visited.find(currNode->right->val)==visited.end()){
//                     q.push({currNode->right,currString+'R'});
//                     visited.insert(currNode->right->val);
//                 }
                
//                 TreeNode* parentNode = parentMapper[currNode->val];
                
//                 if(parentNode && visited.find(parentNode->val)==visited.end()){
//                     q.push({parentNode,currString+'U'});
//                     visited.insert(parentNode->val);
//                 }
                
//             }
//         }
//         return "";
//     void rec(TreeNode* root,TreeNode* parent, int startValue){
//         if(root==NULL) return;
//         if(startValue==root->val) startNode=root;
//         parentMapper[root->val] = parent;
//         rec(root->left,root,startValue);
//         rec(root->right,root,startValue);
//     }