class Solution {
public:
    static bool sortcol(const vector<int>& v1,const vector<int>& v2 ) {
        return v1[0] < v2[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int total = 8;
        vector<vector<int>> result;
        sort(intervals.begin(),intervals.end());
        int start = intervals[0][0];
        int end = intervals[0][1];
        // cout<<"Start"<<start;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0] <= end){
                 end = max(end,intervals[i][1]);
            }else{
                result.push_back({start,end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
            
        }
        result.push_back({start,end});
        return result;
    }
};