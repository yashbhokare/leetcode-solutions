class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string,int> mapper = {
            {"M",1000},
            {"CM",900},
            {"D",500},
            {"CD",400}, 
            {"C",100},
            {"XC",90},
            {"L",50},
            {"XL",40},
            {"X",10},
            {"IX",9},
            {"V",5}, 
            {"IV",4},
            {"I",1}
        };
         int result = 0;
        for(int i=0;i<s.size();i++){
            string temp = "";
            if((i+1)<s.size()){
                temp+=s[i];
                temp+=s[i+1];
                // cout<<temp<<endl;
                if(mapper.find(temp)!=mapper.end()){
                    result+=mapper[temp];
                    i++;
                    continue;
                }  
                temp="";
            }
            temp+=s[i];
            // cout<<temp<<endl;
            result+=mapper[temp];
            
        }
       
        return result;
        
    }
};