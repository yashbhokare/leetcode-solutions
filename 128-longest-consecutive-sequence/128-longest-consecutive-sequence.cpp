class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet;
        for(auto& num:nums){
            numSet.insert(num);
        }
        
        int longestStreak=0;
        int result=0;
         for(auto& num:nums){
             if(numSet.find(num-1)==numSet.end()){
                 longestStreak=1;
                 while(numSet.find(num+1)!=numSet.end()){
                     num++;
                     longestStreak++;
                 }
                 
                 result=max(result,longestStreak);
             }
         }
        return result;
    }
};