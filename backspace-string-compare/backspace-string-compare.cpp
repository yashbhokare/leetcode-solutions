
class Solution {
public:
    bool backspaceCompare(string S, string T) {
            
         stack <int> s1,s2;
         string str1,str2; 
            
         for(int i = 0; i < S.size(); i++){
                 if(S[i] == '#' && !s1.empty())
                         s1.pop();
                 
                 else if(S[i] != '#')
                         s1.push(S[i]);
         }
         
         for(int i = 0; i < T.size(); i++){
                 if(T[i] == '#' && !s2.empty())
                         s2.pop();
                 
                 else if(T[i] != '#')
                         s2.push(T[i]);
                 
         }
         while(!s1.empty() && !s2.empty()){
                if(s1.top()!=s2.top()) return false;
                s1.pop();
                s2.pop();
                 
         }

         return s1.empty() && s2.empty();   
    }
};