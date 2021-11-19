class Solution {
    static bool comparator(vector<int>& a,vector<int>& b){
        return a[1] < b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 1) return 0;
        sort(intervals.begin(),intervals.end());
        sort(intervals.begin(),intervals.end(),comparator);
        int start = intervals[0][0];
        int end = intervals[0][1];
        int ans = 0;
        for(int i=1;i<intervals.size();i++){
            // cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
            if(end > intervals[i][0]){
                ans++;
            }else {
                end = intervals[i][1];
            }
        }
        return ans;
    }
};