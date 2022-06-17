class Solution {
public:
    int majorityElementHashSet(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mapper;
        for(auto num:nums){
            mapper[num]++;
            if(mapper[num]>n/2) return num;
        }
        return 0;
    }


//Boyer-Moore Voting Algorithm
    int majorityElement(vector<int>& nums) {
        int candidate = -1;
        int count = 0;
        for(auto num:nums){
            if(count==0){
                candidate = num;
            }
            
            if(candidate==num){
                count++;
            }else {
                count--;
            }
        }
        return candidate;
        
    }
    
};