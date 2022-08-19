class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> subsequence;
        unordered_map<int,int> frequency;
        for(auto num:nums){
            frequency[num]++;
        }
        for(auto num:nums){
            if(frequency[num]==0){
                continue;
            }
            else if(subsequence[num-1]>0){
                subsequence[num-1]--;
                subsequence[num]++;
            }else if(frequency[num+1]>0 && frequency[num+2]>0){
                frequency[num+1]--;
                frequency[num+2]--;
                subsequence[num+2]++;
            }else {
                return false;
            }
            frequency[num]--;
        }
        return true;
    }
};