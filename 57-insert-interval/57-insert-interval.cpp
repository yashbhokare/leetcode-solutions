class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        return insertInterval(intervals,newInterval);
    }
    
     vector<vector<int>> insertInterval(vector<vector<int>>& intervals, vector<int>& newInterval){
        vector<vector<int>> merged;
         
        // Traverse until the new interval is greater than the last end
      
        int n = intervals.size();
        // if(n==0) {
        //     merged.push_back(newInterval);
        //     return merged;
        // };
        int index=0;
         // Traverse until the new interval is greater than the last end
        while(index<n && intervals[index][1]<newInterval[0]){
            merged.push_back(intervals[index]);
            index++;
        }
        
        if(index<n && newInterval[0]>=intervals[index][0]){
            intervals[index][1]=max(intervals[index][1],newInterval[1]);
            merged.push_back(intervals[index++]);
        }else {
            merged.push_back(newInterval);
        }

        // Merge intervals
        for(int i=index;i<n;i++){
                if(merged.size()!=0 && intervals[i][0]<=merged.back()[1]){
                    merged.back()[1] = max(merged.back()[1],intervals[i][1]);
                }else {
                     merged.push_back(intervals[i]);
                }
        }
         
         return merged;
     }
};