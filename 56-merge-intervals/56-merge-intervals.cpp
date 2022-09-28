class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;
        sort(intervals.begin(),intervals.end());
        for(auto interval:intervals){
            if(merged.size()!=0 && interval[0]<=merged.back()[1]){
                merged.back()[1]=max(merged.back()[1],interval[1]);
            }else {
                merged.push_back(interval);
            }
        }
        return merged;
    }
};