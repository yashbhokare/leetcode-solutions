class Solution {
    static bool comparator(vector<int> a,vector<int> b){
        return a[1] < b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 1) return 0;
        sort(intervals.begin(),intervals.end());
        int end = intervals[0][1];
        int ans = 0;
        for(int i=1;i<intervals.size();i++){
            if(end > intervals[i][0]){
                if(end > intervals[i][1]){
                    end = intervals[i][1];
                }
                ans++;
            }else {
                end = intervals[i][1];
            }
        }
        return ans;
    }
};