class Solution {
public:
    vector<string> mapper= {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
     vector<string> result;
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        string curr="";
        recursion(0,digits,curr);
        return result;
    }
    
    void recursion(int index,string digits,string curr){
        if(curr.size()==digits.size()){
            result.push_back(curr);
            return;
        }
        int digit = digits[index]-'0';
        for(auto ch:mapper[digit]){
            curr.push_back(ch);
            recursion(index+1,digits,curr);
            curr.pop_back();
        }
        
    }
};