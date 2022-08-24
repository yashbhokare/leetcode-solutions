class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> merged;
        
        int index = 0;
        
        while(index<intervals.size() && intervals[index][0] < newInterval[0]){
            merged.push_back(intervals[index++]);
        }
        
        if(merged.empty() || newInterval[0] > merged.back()[1]){
            merged.push_back(newInterval);
        }else {
            merged.back()[0] = min(merged.back()[0],newInterval[0]);
            merged.back()[1] = max(merged.back()[1],newInterval[1]);
        }

        for(int i=index;i<intervals.size();i++){
            if(merged.empty() || merged.back()[1] < intervals[i][0]){
                merged.push_back(intervals[i]);
            }else {
                merged.back()[1] = max(merged.back()[1],intervals[i][1]);
            }

        }
        return merged;
    }
};