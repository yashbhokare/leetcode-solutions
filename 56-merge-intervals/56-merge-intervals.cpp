// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         sort(intervals.begin(),intervals.end());
//         int start = intervals[0][0];
//         int end =  intervals[0][1];
//         vector<vector<int>> result;
//         for(int i=1;i<intervals.size();i++){
//             if(end>=intervals[i][0]){
//                 start = min(start,intervals[i][0]);
//                 end = max(end,intervals[i][1]);
//             }else {
//                 result.push_back({start,end});
//                 start = intervals[i][0];
//                 end = intervals[i][1];
//             }
//         }
//          result.push_back({start,end});
//         return result;
//     }
// };

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        for (auto interval : intervals) {
            // if the list of merged intervals is empty or if the current
            // interval does not overlap with the previous, simply append it.
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);
            }
            // otherwise, there is overlap, so we merge the current and previous
            // intervals.
            else {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        return merged;
    }
};