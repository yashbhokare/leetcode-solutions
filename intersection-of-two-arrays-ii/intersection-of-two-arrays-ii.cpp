class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() >= nums2.size()){
            return calculateIntersect(nums1,nums2);
        } else {
            return calculateIntersect(nums2,nums1);
        }
    }
    
    vector<int> calculateIntersect(vector<int>& nums1, vector<int>& nums2){
        // unordered_mulitset is used which can store duplicate elements
        unordered_multiset <int> numSet;
        vector<int> result; // Final result
        for(int i=0; i<nums2.size(); i++){
            numSet.insert(nums2[i]);
        }
        
        for(int i=0; i<nums1.size(); i++){
            // find function returns iterator to first position of found value we can pass this iterator to erase instead of actual value to delete only one copy
            const auto it = numSet.find(nums1[i]);
            if(it != numSet.end()){
                result.push_back(nums1[i]);
                numSet.erase(it);
            }
        }
        return result;
        
    }
};