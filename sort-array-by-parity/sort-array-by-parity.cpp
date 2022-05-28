class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
       //  int left=0,right=nums.size()-1;
       // while(left<=right){
       //      if(nums[left]%2==0){
       //          left++;
       //      } else{
       //         swap(nums[left],nums[right]);
       //          right--;
       //      };
       //  }
       //  return nums;
        
        int n=nums.size();
        //vector<int>arr;
         int j=-1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==0)
            {
                j++;
                swap(nums[i],nums[j]);
            }
        }
        return nums;
    }
    
    vector<int> sortArrayByParityWithNewArray(vector<int>& nums) {
        vector<int> result(nums.size());
        int left=0,right=nums.size()-1;
        for(auto& num:nums){
            if(num%2==0) result[left++]=num;
            else result[right--]=num;
        }
        return result;
    }
};