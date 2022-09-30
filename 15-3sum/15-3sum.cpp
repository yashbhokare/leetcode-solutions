class Solution {
public:
    int n;
    vector<vector<int>> threeSum(vector<int>& nums) {
        int target = 0;
        n = nums.size();
        sort(nums.begin(),nums.end());
        return kth(nums,0,n-1,0,3);
//         vector<vector<int>> ans;
//         for(int i=0;i<n;i++){
//             if(i!=0 && nums[i]==nums[i-1]) continue;
            
//             int new_target = target -  nums[i];
//             for(auto num:twoSum(nums,i+1,n-1,new_target)){
//                 num.push_back(nums[i]);
//                 ans.push_back(num);
//             }
//         }
//         return ans;
    }
    
    vector<vector<int>> kth(vector<int>& nums,int l,int r,int target,int k) {
        if(l>r) return {};
        
        if(k==2){
            return twoSum(nums,l,r,target);
        }
        
        vector<vector<int>> ans;
        for(int i=l;i<n;i++){
            if(i!=0 && nums[i]==nums[i-1]) continue;
            
            int new_target = target -  nums[i];
            for(auto num:kth(nums,i+1,n-1,new_target,k-1)){
                num.push_back(nums[i]);
                ans.push_back(num);
            }
        }
        return ans;
    }    
    vector<vector<int>> twoSum(vector<int>& nums,int l,int r,int target){
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
            
            int sum = nums[left]+nums[right];
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