class Solution {
public:
    vector<string> mappings = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}, ans;    
    vector<string> result;
    
    vector<string> letterCombinations(string digits) {
      if(digits=="") return {};
        helper(digits,0,"");
        return  result;
    }
    // recursive helper function
    void helper(string &digits, int i, string combi){	
        if(i==digits.size()){ 
            result.push_back(combi);
            return;    
        }
        for(auto ch:mappings[digits[i]-'2'])
            helper(digits,i+1,combi+ch);
    }
};