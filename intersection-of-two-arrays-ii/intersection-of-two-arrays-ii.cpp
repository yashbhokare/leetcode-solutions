class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_multiset<int> set;
        for(auto num:nums1) set.insert(num);
        for(auto num:nums2){
            auto it=set.find(num);
            if(it!=set.end()){
                result.push_back(num);
                set.erase(it);
            }
        }
        return result;
    }
};