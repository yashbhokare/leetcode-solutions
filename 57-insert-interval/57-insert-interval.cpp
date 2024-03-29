class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        return insertInterval(intervals,newInterval);
    }
    
     vector<vector<int>> insertInterval(vector<vector<int>>& intervals, vector<int>& newInterval){
        vector<vector<int>> merged;
         
        // Traverse until the new interval is greater than the last end
      
        int n = intervals.size();

        int index=0;
         // Traverse until the new interval is greater than the last end
        while(index<n && intervals[index][1]<newInterval[0]){
            merged.push_back(intervals[index]);
            index++;
        }
        
         // Step 2 : Check to merge the current interval based on the start value
        if(index<n && newInterval[0]>=intervals[index][0]){
            intervals[index][1]=max(intervals[index][1],newInterval[1]);
            merged.push_back(intervals[index++]);
        }else {
            merged.push_back(newInterval);
        }
         
        // Step 2.a : To ignore step 2 just uncomment the below line and comment step 2
        // merged.push_back(newInterval);

        // Merge intervals
        for(int i=index;i<n;i++){
                if(merged.size()!=0 && intervals[i][0]<=merged.back()[1]){
                    // merged.back()[0] = min(merged.back()[0],intervals[i][0]);
                    // If you're doing step 2.a then check for the min value as well
                    merged.back()[1] = max(merged.back()[1],intervals[i][1]);
                }else {
                     merged.push_back(intervals[i]);
                }
        }
         
         return merged;
     }
};