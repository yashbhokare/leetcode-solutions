class Solution {
public:
    
vector<vector<int>> twoSum(vector<int>& nums, int target,int index){
        vector<vector<int>> result;
        int start = index;
        int last = nums.size()-1;
        while(start<last){
            int sum = nums[start] + nums[last];
            if(sum < target || (start > index && nums[start] == nums[start-1])){
                start++;
            }
            else if(sum > target || (last < nums.size()-1 && nums[last] == nums[last+1])){
                last--;
            } else {
                result.push_back({nums[start],nums[last]});
                start ++;
                last--;
            }
        }
        return result;
        
    }
    
    vector<vector<int>> kSum(vector<int>& nums, int target, int k,int start){
        if(k==2){
            return twoSum(nums,target,start);
        }
        vector<vector<int>> result;
        for(int i=start;i<nums.size();i++){
            if(i == start || nums[i] != nums[i-1] ){
                int newTarget = target - nums[i];
                vector<vector<int>> response = kSum(nums,newTarget,k-1,i+1);
                for(int j = 0 ; j<response.size();j++){
                    response[j].insert(response[j].begin(),nums[i]);
                    result.push_back(response[j]);
                }  
            }

        }
        return result;
    }
    
    
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        
        return kSum(nums,target,4,0);
    }
    

};