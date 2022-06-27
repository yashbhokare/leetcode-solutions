class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool dec = false;
        for(int i=1;i<nums.size();i++){
            if(!dec && nums[i]<nums[i-1]){
                dec = true;
                if(i>1 && nums[i-2]>nums[i]){
                    nums[i] = nums[i-1];
                }else {
                    nums[i-1] = nums[i];
                }
            }else if(dec && nums[i]<nums[i-1]){
                return false;

                
            }
            
        }
        return true;
    }
};