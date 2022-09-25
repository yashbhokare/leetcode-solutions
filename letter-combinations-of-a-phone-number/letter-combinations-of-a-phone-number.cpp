class Solution {
public:
    vector<string> mapper= {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> result;
    vector<string> letterCombinations(string digits) {
        string s="";
        if(digits.size()==0) return {};
        rec(0,s,digits);
        return result;
    }
    
    void rec(int index,string s,string digits){
        if(index==digits.size()){
            result.push_back(s);
            return;
        }
        int num = digits[index]-'0';
        for(auto ch:mapper[num]){
            s.push_back(ch);
            rec(index+1,s,digits);
            s.pop_back();
        }
    }
    
    
};

// Time complexity: O(4^N x N), where N is the length of digits. Note that 4 in this expression is referring to the maximum value length in the hash map, and not to the length of the input.