class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int totalLength = nums.size();
        int oneExist = false;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
               oneExist= true;
            };
            if(nums[i]<1 || nums[i]>totalLength){
                nums[i]=1;
            }
        }
        if(!oneExist) return 1;
        
        for(int i=0;i<nums.size();i++){
            int index = abs(nums[i])-1;
            nums[index] = abs(nums[index])*-1;
        }
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0) return i+1;
        }
        return totalLength+1;
    }
};