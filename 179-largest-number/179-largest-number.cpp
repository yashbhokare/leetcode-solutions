class Solution {
public:
    static auto comparator(string a, string b){
        string order1=a+b;
        string order2=b+a;
        return order1 > order2;
    }
    string largestNumber(vector<int>& nums) {
        string res="";
        vector<string> numString;
        for(int i=0;i<nums.size();i++){
            numString.push_back(to_string(nums[i]));
        }
        sort(numString.begin(),numString.end(),comparator);
        
        if(numString[0][0]=='0') return "0";
        for(int i=0;i<numString.size();i++){
            res=res+numString[i];
        }
        return res;
    }
};