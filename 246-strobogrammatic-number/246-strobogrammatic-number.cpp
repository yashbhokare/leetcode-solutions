class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char,char> mapper = {
            {'0','0'},
            {'1','1'},
            {'6','9'},
            {'9','6'},
            {'8','8'}
        };
        
        int start = 0;
        int end = num.size()-1;
        while(start<=end){
            if(mapper.find(num[start])==mapper.end() || mapper[num[start]]!=num[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};