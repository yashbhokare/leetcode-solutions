class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> merged;
        int idx=0;
        while(idx<intervals.size() && intervals[idx][1]<newInterval[0]){
            merged.push_back(intervals[idx]);
            idx++;
        }
        //TODO
        merged.push_back(newInterval);
        
        for(int i=idx;i<intervals.size();i++){
            if(merged.size()!=0 && merged.back()[1]>=intervals[i][0]){
                merged.back()[0] = min(intervals[i][0],merged.back()[0]);
                merged.back()[1] = max(intervals[i][1],merged.back()[1]);
            }else {
                merged.push_back(intervals[i]);
            }
        }
        
        return merged;
        
        
    }
};