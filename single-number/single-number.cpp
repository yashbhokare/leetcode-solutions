class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> hashSet;
        int result=0;
        for(int num:nums){
            result = result ^ num;
            // if(hashSet.count(num)>0){
            //     hashSet.erase(num);
            // }else {
            //     hashSet.insert(num);
            // }
        }
        return result;
        // return *hashSet.begin();
    }
};