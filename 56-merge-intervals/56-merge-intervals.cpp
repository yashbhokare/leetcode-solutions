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
        vector<vector<int>> merged;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size();i++){
            if(i!=0 && intervals[i][0]<=merged.back()[1]){
                merged.back()[1] = max(merged.back()[1],intervals[i][1]);
            }
            else {
                merged.push_back(intervals[i]);
            }
        }
        return merged;
    }
};