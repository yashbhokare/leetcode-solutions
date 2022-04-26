class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        return twoSumPractice(nums,target);
    }
    
    vector<int> twoSumCalculation(vector<int> numbers, int target){
        unordered_map <int,int> numberList;
        vector<int> finalResult;
        for(int i=0;i< numbers.size();i++){
            int calculate = target - numbers[i];
            auto iterator = numberList.find(calculate);
            if(iterator != numberList.end()){
                finalResult.push_back(iterator->second);
                finalResult.push_back(i);
                break;
            }
            numberList.insert({numbers[i],i});
        }
        return finalResult;
    }
    
    vector<int> twoSumPractice(vector<int>& nums, int target){
        unordered_map<int,int> mapper;
        for(int i=0;i<nums.size();i++){
            int diff = target - nums[i];
            auto it = mapper.find(diff);
            if(it!=mapper.end()){
                return {it->second,i};
            }
            mapper.insert({nums[i],i});
        }
        
        return {};
    }
};

