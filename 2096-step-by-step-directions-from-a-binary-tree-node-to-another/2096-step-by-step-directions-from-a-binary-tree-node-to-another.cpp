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
    }

    
    bool traverse(TreeNode* root, int target, string& s){
            if(root==NULL) return false;
            if(root->val==target) {
                
                return true;
            }
            
            if(root->left){
                s.push_back('L');
                if(traverse(root->left,target,s)){
                    return true;
                }
                s.pop_back();
            }
            if(root->right){
                s.push_back('R');
                if(traverse(root->right,target,s));{
                    return true;
                }
                s.pop_back();
            }
        return false;
        
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