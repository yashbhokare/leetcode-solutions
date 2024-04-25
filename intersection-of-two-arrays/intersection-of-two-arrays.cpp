class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_set<int> num1hashSet;
        if(nums1.size() <1 || nums2.size() < 1){
            return {};
        }
        for(int i=0;i<nums1.size();i++){
            num1hashSet.insert(nums1[i]);
        }
        for(int j=0;j<nums2.size();j++){
            if(num1hashSet.find(nums2[j]) != num1hashSet.end()){
                result.push_back(nums2[j]);
                num1hashSet.erase(nums2[j]);
            }
        }
        return result;
    }
};