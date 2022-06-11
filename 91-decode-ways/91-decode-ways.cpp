class Solution {
public:
    int result=0;
    unordered_set<string> set;
    unordered_map<string,int> mapper;
    int numDecodings(string s) {
        for(int i=1;i<=26;i++){
            set.insert(to_string(i));
        }
        return recursion(0,s);
    }
    
    int recursion(int index,string s){
        if(index==s.size()){
            result++;
            return 1; 
        }
        
        string newS = s.substr(0,index);
        cout<<newS<<endl;
        if(mapper.find(newS)!=mapper.end()){
            return mapper[newS];
        }
        
        string s1{s[index]};
        int val1 = 0;
        if(set.find(s1)!=set.end()){
            val1 = recursion(index+1,s);
        }
        int val2 =0;
        if(index+1<s.size()){
            string s2 {s[index],s[index+1]};
            if(set.find(s2)!=set.end()){
                val2 = recursion(index+2,s);
            }
            
        }
        mapper[newS] = val1+val2;
        return mapper[newS];
    }
};