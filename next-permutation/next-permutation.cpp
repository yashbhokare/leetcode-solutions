class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = -1;
        
        for(int i=nums.size()-1;i>=1;i--){
            if(nums[i] > nums[i-1]){
                index = i-1;
                break;
            }
        }
        cout<<index<<endl;
        if(index!=-1){
            int minValue = INT_MAX;
            int swapIndex = 0;
            for(int i=index+1;i<nums.size();i++){
                if(nums[i]>nums[index] && minValue>=nums[i] ){
                    minValue = nums[i];
                    swapIndex = i;
                }
            }
            swap(nums[index],nums[swapIndex]);
        } 

        reverse(nums.begin()+index+1,nums.end());
    }
};