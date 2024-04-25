class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> hashSet;
        for(int num:nums){
            if(hashSet.count(num)>0){
                hashSet.erase(num);
            }else {
                hashSet.insert(num);
            }
        }
        return *hashSet.begin();
        
    }
};