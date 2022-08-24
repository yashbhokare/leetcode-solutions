class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int maxR = matrix.size();
        int maxC = matrix[0].size();
        vector<int> topLeft = {0,0};
        vector<int> topRight ={0,maxC-1};
        vector<int> bottomLeft = {maxR-1,0};
        vector<int> bottomRight = {maxR-1,maxC-1};
       
        while(result.size() < maxR*maxC){
           
            // Left to right
            for(int col=topLeft[1];col<=topRight[1];col++){
                result.push_back(matrix[topLeft[0]][col]);
            }
            
  
            // Right Top to Right Bottom
            for(int row =topRight[0]+1;row<=bottomRight[0];row++){
                result.push_back(matrix[row][topRight[1]]);
            }

            
            if(topLeft[0]!=bottomRight[0])
            {
                //Right Bottom to Left Bottom
                for(int col=bottomRight[1]-1;col>=bottomLeft[1];col--){
                    result.push_back(matrix[bottomRight[0]][col]);
                }
            }
            
            if(topLeft[1]!=bottomRight[1]){
                // Left Bottom to Left Top
                for(int row =bottomLeft[0]-1;row>=topLeft[0]+1;row--){
                    result.push_back(matrix[row][bottomLeft[1]]);
                }
            }

            topLeft[0]++;
            topLeft[1]++;
            topRight[0]++;
            topRight[1]--;
            bottomLeft[0]--;
            bottomLeft[1]++;
            bottomRight[0]--;
            bottomRight[1]--;
        }
        return result;
    }
};