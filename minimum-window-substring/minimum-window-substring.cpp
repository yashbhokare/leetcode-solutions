class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";
        if( t == s) return t;
        unordered_map<char,int> mapper;
        for(int i=0;i<t.size();i++){
            mapper[t[i]]++;
        }
        
        int minSize = INT_MAX;
        int left =0;
        int right=0;
        int startPos = 0;
        int req = mapper.size();
        unordered_map<char,int> window;
        while(right<s.size()){
            
            if(mapper.find(s[right]) != mapper.end()){
                window[s[right]]++;
                if(window[s[right]] == mapper[s[right]]){
                    req--;
                }
            }
            cout<<req<<endl;
            while(req==0){
                //Store the result
                if(right-left+1 < minSize){
                    minSize = right-left+1;
                    startPos = left;
                }
                
                if(mapper.find(s[left]) != mapper.end()){
                    window[s[left]]--;
                    if(window[s[left]] < mapper[s[left]]){
                        req++;
                    }
                }
                left++;
                
            }
            
            right++;
            
        }
        cout<<startPos<<endl;
        cout<<minSize;
        if(minSize == INT_MAX) return "";
        return s.substr(startPos,minSize);
    }
};