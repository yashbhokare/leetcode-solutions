class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char,char> mapper = {
            {'6','9'},
            {'9','6'},
            {'1','1'},
            {'8','8'},
            {'0','0'}
        };
        
        int n = num.size();
        for(int i=0;i<n+1/2;i++){
            if(mapper[num[i]]==num[n-1-i] || num[i]==mapper[num[n-1-i]]) continue;
            return false;
        }
        return true;

    }
};