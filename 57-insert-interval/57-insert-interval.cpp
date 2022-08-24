class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> merged;
        
        // Only change comapred to merge intervals
        intervals.push_back(newInterval);
        
        sort(intervals.begin(),intervals.end());
        for(auto interval:intervals){
            if(merged.empty() || merged.back()[1] < interval[0]){
                merged.push_back(interval);
            }else {
                merged.back()[1] = max(merged.back()[1],interval[1]);
            }
        }
        return merged;
    }
};