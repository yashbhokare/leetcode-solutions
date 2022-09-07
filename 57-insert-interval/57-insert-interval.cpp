class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        return insertInterval(intervals,newInterval);
    }
    
     vector<vector<int>> insertInterval(vector<vector<int>>& intervals, vector<int>& newInterval){
         vector<vector<int>> merged;
         
         // Traverse until the start is greater
         int index=0;
         while(index<intervals.size() && intervals[index][1]<newInterval[0]){
            merged.push_back({intervals[index][0],intervals[index][1]});
            index++;
         }
         
         merged.push_back({newInterval[0],newInterval[1]});
         
         // Merge Interval
         for(int i =index;i<intervals.size();i++){
             if(intervals[i][0]<=merged.back()[1]){
                 merged.back()[0] = min(merged.back()[0],intervals[i][0]);
                 merged.back()[1] = max(merged.back()[1],intervals[i][1]);
             }else {
                 merged.push_back(intervals[i]);
             }
         }
         return merged;
     }
};