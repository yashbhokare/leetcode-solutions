class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        vector<vector<int>> mergedArray;
        int end=points[0][1];
        int start=points[0][0];
        
        for(int i=1;i<points.size();i++){
            
            if(end>=points[i][0]){
                start=max(start,points[i][0]);
                end=min(end,points[i][1]);
            }else {
                mergedArray.push_back({start,end});
                start=points[i][0];
                end=points[i][1];
            }
        }
        mergedArray.push_back({start,end});
        // for(int i=0;i<mergedArray.size();i++){
        //      cout<<mergedArray[i][0]<<","<<mergedArray[i][1]<<endl;
        //  }
        return mergedArray.size();
    }
};