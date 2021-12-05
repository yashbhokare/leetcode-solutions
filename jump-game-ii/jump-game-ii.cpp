class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps=0,farthest=0,currentEnd = 0;
        for(int i=0;i<nums.size()-1;i++){
            farthest = max(farthest,nums[i]+i);
            if(i==currentEnd){
                jumps++;
                currentEnd = farthest;
            }
        }
        return jumps;
    }
};