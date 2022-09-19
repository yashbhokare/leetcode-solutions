class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mapper = {
            {'M',1000},
            {'D',500},
            {'C',100},
            {'L',50},
            {'X',10},
            {'V',5}, 
            {'I',1}
        };
         int result = 0;
        for(int i=0;i<s.size();i++){
            if(i+1<s.size() && mapper[s[i]]<mapper[s[i+1]]){
                result+=mapper[s[i+1]]-mapper[s[i]];
                i++;
            }else {
                result+=mapper[s[i]];
            }
        }
       
        return result;
        
    }
};