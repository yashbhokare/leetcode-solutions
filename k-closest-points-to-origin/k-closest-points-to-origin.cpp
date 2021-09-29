class Solution {
public:
    static bool comp(const vector<int>& a,const vector<int>& b){
        return a[0] < b[0];
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> pointsVector;
        vector<vector<int>> result;
        int calculate = 0;        
        for(int i=0;i<points.size();i++){
            calculate = pow(points[i][0],2) + pow(points[i][1],2);
            pointsVector.push_back({calculate,points[i][0],points[i][1]});
        }
        sort(pointsVector.begin(),pointsVector.end());
        for(int i=0;i<k;i++){
            result.push_back({pointsVector[i][1],pointsVector[i][2]});
        }
                
        return result;
        

    }
};