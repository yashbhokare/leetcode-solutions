class Solution {
public:
    
    
    string crackSafe(int n, int k) {
        
        return dfs_crackSafe(n,k);
    }
    

    int finalSize = 0;
    unordered_set<string> visited;
    // Using DFS
    string dfs_crackSafe(int n, int k){
        string pwd(n,'0');
        visited.insert(pwd);
        finalSize = (int)pow(k,n);
        dfs(pwd,n,k);
        return pwd;
    }
    
    bool dfs(string& pwd,int n,int k){
        if(visited.size()==finalSize){
            return true;
        }
        
        string lastSubString = pwd.substr(pwd.size()-n+1);
        for(char ch='0';ch<k+'0';ch++){
            string newComb =lastSubString+ch;
            if(visited.find(newComb)==visited.end()){
                visited.insert(newComb);
                pwd.push_back(ch);
                if(dfs(pwd,n,k)) return true;
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
            for(int j = k-1;j>=0;j--){
                string now = prev + to_string(j);
                if(!visited.count(now)){
                    visited.insert(now);
                    ans += to_string(j);
                    break;
                }
            }
        }
        return ans;
    }
};