class Solution {
public:
    unordered_map<int,unordered_map<int,int>> matrix;
    int minAreaRect(vector<vector<int>>& points) {
        int minArea = INT_MAX;
        for(auto p:points){
               matrix[p[0]][p[1]] = 1;
        }
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                int x1= points[i][0];
                int y1= points[i][1];
                int x2= points[j][0];
                int y2= points[j][1];
                if(x1!=x2 && y1!=y2){
                    if(matrix[x1][y2] && matrix[x2][y1]){
                        int area = abs(x2-x1)*abs(y2-y1);
                        minArea = min(area,minArea);
                    }
                }
            }
        }
        
        return minArea==INT_MAX ? 0 : minArea;
    }
};