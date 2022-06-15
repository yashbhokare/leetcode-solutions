class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int startNew = newInterval[0];
        int endNew = newInterval[1];
        vector<vector<int>> result;
        bool pushed =false;

        for(int i=0;i<intervals.size();i++){
            
            if(!pushed &&(startNew>=intervals[i][0] && startNew<=intervals[i][1]) || (endNew>=intervals[i][0] && endNew<=intervals[i][1]) ||(intervals[i][0]>=startNew && intervals[i][1]<=endNew) ){
                startNew = min(startNew,intervals[i][0]);
                endNew = max(endNew,intervals[i][1]);
                continue;
            }
            
            if(!pushed && endNew<intervals[i][0]){
                result.push_back({startNew,endNew});
                pushed= true;
            }
            
             result.push_back(intervals[i]);
            
        }
        if(!pushed) result.push_back({startNew,endNew});
        return result;
    }
};