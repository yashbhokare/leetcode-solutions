class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        
        if(nums.size()==0) return {mergeNumber(lower,upper)};
        
        vector<string> result;
        string init = startString(lower,nums[0]);
        if(init.size()>0) result.push_back(init);
        
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]+1){
                result.push_back(mergeNumber(nums[i-1]+1,nums[i]-1));
            }
        }
        string endVal = endString(upper,nums[nums.size()-1]);
        if(endVal.size()>0) result.push_back(endVal);
        
        return result;
    }
    
    string startString(int lower, int start){
           if(start==lower) return "";
            return mergeNumber(lower,start-1);
    }
    
    string endString(int higher, int last){
           if(last==higher) return "";
            return mergeNumber(last+1,higher);
    }
    
    string mergeNumber(int a,int b){
        if(a==b) return to_string(a);
        return to_string(a) + "->" + to_string(b);
    }

};