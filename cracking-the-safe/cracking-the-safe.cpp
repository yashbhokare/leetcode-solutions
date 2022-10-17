
//De Bruijn sequence
// Hamilton Graph can also be used

class Solution {
public:
    string crackSafe(int n, int k) {
        return greedy_crackSafe(n,k);
        
    }
    // Using DFS
    //https://leetcode.com/problems/cracking-the-safe/discuss/153039/DFS-with-Explanations
    string dfs_crackSafe(int n, int k){
       
        unordered_set<string> visited;
        string pwd(n,'0');
        visited.insert(pwd);
        int finalSize = (int)pow(k,n);
        dfs(pwd,visited,n,k,finalSize);
        return pwd;
    }
    
    bool dfs(string& pwd,unordered_set<string>& visited,int n,int k,int finalSize){
        if(visited.size()==finalSize){
            return true;
        }
        string lastSubString = pwd.substr(pwd.size()-n+1);
        for(char ch='0';ch<k+'0';ch++){
            string newComb =lastSubString+ch;
            if(visited.find(newComb)==visited.end()){
                visited.insert(newComb);
                pwd.push_back(ch);
                if(dfs(pwd,visited,n,k,finalSize)) return true;
                visited.erase(newComb);
                pwd.pop_back();
            }
        }
        return false;
    }
    
    
    // Greedy Approach
    string greedy_crackSafe(int n, int k) {
        string ans = string(n, '0');
        unordered_set<string> visited;
        visited.insert(ans);
        
        for(int i = 0;i<pow(k,n);i++){
            string prev = ans.substr(ans.size()-n+1,n-1);
            bool visit = true;
            for(int j = k-1;j>=0;j--){
                string now = prev + to_string(j);
                if(!visited.count(now)){
                    visit = false;
                    // cout<<to_string(j)<<endl;
                    visited.insert(now);
                    ans += to_string(j);
                    break;
                }
            }
            if(visit){
                break;
                // cout<<prev<<endl;
                visit = true;
            }
        }
        return ans;
    }
};