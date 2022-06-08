class Solution {
public:
    unordered_map<int,int> mapper;
    unordered_map<int,int> memo;
    int deleteAndEarn(vector<int>& nums) {
        int maxNum=0;
        for(auto& num:nums){
            mapper[num]=mapper[num]+num;
            maxNum=max(maxNum,num);
        }
        return rec(maxNum);
    }
    
    int rec(int num){
        if(num==0) return 0;
        if(num==1) return mapper[num];
        if(memo.find(num)!=memo.end()) return memo[num];
        int gain=mapper[num];
        int maxVal = max(gain+rec(num-2),rec(num-1));
        memo[num]= maxVal;
        return maxVal;
    }
};