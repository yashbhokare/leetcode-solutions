class Solution {
public:  
    int n;
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        n = nums.size();
        sort(nums.begin(),nums.end());
        return kth(nums,0,n-1,target,4);

    }

  

    
    vector<vector<int>> kth(vector<int>& nums,int l,int r,long target,int k) {
        if(l>r) return {};
        
        if(k==2){
            return twoSum(nums,l,r,target);
        }
        
        vector<vector<int>> ans;
        for(int i=l;i<n;i++){
            if(i!=l && nums[i]==nums[i-1]) continue;
            
            long new_target = target -  nums[i];
            for(auto num:kth(nums,i+1,n-1,new_target,k-1)){
                num.push_back(nums[i]);
                ans.push_back(num);
            }
        }
        return ans;
    }    
    vector<vector<int>> twoSum(vector<int>& nums,int l,int r,long target){
        int left=l;
        int right =r;
        vector<vector<int>> result;
        while(left<right){
            if(left!=l && nums[left]==nums[left-1]){
                left++;
                continue;
            }
            
            if(right!=r && nums[right]==nums[right+1]){
                right--;
                continue;
            }
            
            long sum = nums[left]+nums[right];
            if(sum==target){
                result.push_back({nums[left],nums[right]});
                left++;
                right--;
            }else if(sum>target){
                right--;
            }else {
                left++;
            }
        }
        return result;
    }
};