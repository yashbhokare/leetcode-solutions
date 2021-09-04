class Solution {
public:
    static bool comp(const vector<int>& a,const vector<int>& b){
        return a[0] < b[0];
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        unordered_multimap<int,int> pointsMap;
        vector<vector<int>> pointsVector;
        vector<vector<int>> result;
        int calculate = 0;        
        for(int i=0;i<points.size();i++){
            calculate = pow(points[i][0],2) + pow(points[i][1],2);
            // pointsMap.insert({calculate,i});
            pointsVector.push_back({calculate,points[i][0],points[i][1]});
        }
        sort(pointsVector.begin(),pointsVector.end(),comp);
        
        // for(int i=0;i<pointsVector.size();i++){
        //     cout<<pointsVector[i][0]<<"  "<<pointsVector[i][1]<<","<<pointsVector[i][2]<<endl;
        // }
        // cout<<"Ans Map"<<endl;
        int i=0;
        // for(auto it = ordered.begin();i<k; ++it,i++){
        //     cout<<it->first<<endl;
        //     result.push_back({points[it->second][0],points[it->second][1]});
        // }
        for(i=0;i<k;i++){
            result.push_back({pointsVector[i][1],pointsVector[i][2]});
        }
                
        return result;
        

    }
};