class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() ==1) return 1;
        int diff = nums[1] - nums[0];
        int ans = diff == 0 ? 1 : 2;
        for(int i=1;i<nums.size();i++){
            int newDiff = nums[i]-nums[i-1];
            if((diff>=0 && newDiff<0)||(diff<=0 && newDiff>0)){
                ans++;
                diff= newDiff;
            }
        }
        return ans;
    }
};