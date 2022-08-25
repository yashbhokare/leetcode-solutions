// class Solution {
// public:
//     int result=0;
//     unordered_set<string> set;
//     unordered_map<string,int> mapper;
//     int numDecodings(string s) {
//         for(int i=1;i<=26;i++){
//             set.insert(to_string(i));
//         }
//         return recursion(0,s);
//     }
    
//     int recursion(int index,string s){
//         if(index==s.size()){
//             return 1; 
//         }
        
//         string newS = s.substr(0,index);
//         cout<<newS<<endl;
//         if(mapper.find(newS)!=mapper.end()){
//             return mapper[newS];
//         }
        
//         string s1{s[index]};
//         int val1 = 0;
//         if(set.find(s1)!=set.end()){
//             val1 = recursion(index+1,s);
//         }
//         int val2 =0;
//         if(index+1<s.size()){
//             string s2 {s[index],s[index+1]};
//             if(set.find(s2)!=set.end()){
//                 val2 = recursion(index+2,s);
//             }
            
//         }
//         mapper[newS] = val1+val2;
//         return mapper[newS];
//     }
// };

class Solution {
public:
    map<int, int> memo;

    int recursiveWithMemo(int index, string& str) {
        // Have we already seen this substring?
        // cout<<str[index]<<endl;
        if (memo.find(index) != memo.end()) {
            return memo[index];
        }

        // If you reach the end of the string
        // Return 1 for success.
        if (index == str.length()) {
            return 1;
        }

        // If the string starts with a zero, it can't be decoded
        if (str[index] == '0') {
            return 0;
        }

        if (index == str.length() - 1) {
            return 1;
        }

        int ans = recursiveWithMemo(index + 1, str);

        if (stoi(str.substr(index, 2)) <= 26) {
            ans += recursiveWithMemo(index + 2, str);
        }

        // Save for memoization
        memo[index] = ans;

        return ans;
    }

    int numDecodings(string s) {
        return recursiveWithMemo(0, s);
    }
};