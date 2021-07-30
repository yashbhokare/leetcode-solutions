class Solution {
public:
    int firstUniqChar(string s) {
        return firstUniqCharCalculations(s);
        // unordered_set<char> stringSet;
        // bool isDuplicate = false;
        // for(int i=0;i<s.length();i++){
        //     isDuplicate = false;
        //     if(s[i]!='*'){
        //         for(int j=i+1;j<s.length();j++){
        //             if(s[i]==s[j]){
        //                 s[j]='*';
        //                 isDuplicate = true;
        //             };
        //         }
        //         if(isDuplicate) {
        //             s[i] = '*';
        //         } else {
        //             return i;
        //         }
        //         cout<<s<<endl; 
        //     }
        // }
        return -1;
    }
    
    int firstUniqCharCalculations(string s){
        unordered_map<char,int> stringSet;
        for(int i=0;i<s.length();i++){
            const auto it = stringSet.find(s[i]);
            if(it == stringSet.end()){
                stringSet[s[i]] = 1;
            } else {
                stringSet[s[i]] = it->second+1;
            }
        }
        
        for(int i=0;i<s.length();i++){
            const auto it = stringSet.find(s[i]);
            if(it->second == 1){
                return i;
            }
        }
        return -1;

    }
};