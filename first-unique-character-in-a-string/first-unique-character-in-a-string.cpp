class Solution {
public:
    int firstUniqChar(string s) {
        return firstUniqCharCalculation(s);
        return firstUniqCharCalculations(s);
        // return bruteForceTechnique(s);
    }
    
    int firstUniqCharCalculation(string s){
        vector<int> nums(26,0);
        for(int i=0;i<s.length();i++){
            int pos = s[i] - 'a';
            nums[pos]++;    
        }
        for(int i=0;i<s.length();i++){
            int pos = s[i] - 'a';
            if(nums[pos]==1) return i;    
        }
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
    
    int bruteForceTechnique(string s){
        bool isDuplicate = false;
        for(int i=0;i<s.length();i++){
            isDuplicate = false;
            if(s[i]!='*'){
                for(int j=i+1;j<s.length();j++){
                    if(s[i]==s[j]){
                        s[j]='*';
                        isDuplicate = true;
                    };
                }
                if(isDuplicate) {
                    s[i] = '*';
                } else {
                    return i;
                }
                cout<<s<<endl; 
            }
        }
        return -1;
    }
    
//     class Solution {
//     public int firstUniqChar(String s) {
//         int[] count = new int[26];
//         int n = s.length();
//         // build char count bucket : <charIndex, count>
//         for (int i = 0; i < n; i++) {            
//             int index = s.charAt(i) - 'a';
//             count[index]++;
//         }
        
//         // find the index
//         for (int i = 0; i < n; i++) {
//             int index = s.charAt(i) - 'a';
//             if (count[index] == 1) {
//                 return i;
//             }
                
//         }
//         return -1;
//     }

};