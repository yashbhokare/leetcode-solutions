class Solution {
public:
    unordered_map<int,int> memo;
    int numDecodings(string s) {
        return rec(s,0);
    }
    
    int rec(string s,int index){
        if(index>=s.size()){
            return 1;
        }
        if(index>s.size()){
            return 0;
        }
        
        if(s[index]=='0') return 0;
        
        // while(s[index]=='0'){
        //     index++;
        // }
        
        if(memo.find(index)!=memo.end()) return memo[index];
        
        // int ans =0;
        int total = rec(s,index+1);
        if(index+1<s.size() && stoi(s.substr(index,2))<=26){
            total+=rec(s,index+2);
        }
        
        memo[index] = total;
        
        return memo[index];
        
        
    }
};