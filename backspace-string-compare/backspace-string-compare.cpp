class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return trimString(s) == trimString(t);
    }
    
    string trimString(string s){
        for(int i=0;i<s.size()-1;){
            if(!s.size()){
                break;
            }
            if(isalpha(s[i]) && s[i+1]=='#'){
               
                s.erase(i,2);
                i = i-1 < 0 ? 0 : i-1;
                // cout<<i<<endl;
                continue;
            }else if(s[i]=='#'){
                s.erase(i,1);
                i = i-1 < 0 ? 0 : i-1;
                continue;
            }
            i++;
        }
        cout<<s;
        return s;
    }
};