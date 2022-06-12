class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> mapper;
        vector<int> previousTotal(nums.size(),0);
        int left=0;
        int maxRes = 0;
        int totalCount=0;
        for(int right=0;right<nums.size();right++){
            totalCount+=nums[right];
            if(right > 0){
               previousTotal[right]=nums[right-1]+previousTotal[right-1];            
            }
            
            if(mapper.find(nums[right])!=mapper.end()){
                left=max(left,mapper[nums[right]]+1);
            }
            
            mapper[nums[right]] = right;
            
            int subArraySum = totalCount-previousTotal[left];
            maxRes = max(maxRes,subArraySum);
        }
        return maxRes;
    }
};