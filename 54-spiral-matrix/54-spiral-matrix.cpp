class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        
        int m = matrix.size();
        int n = matrix[0].size();
        int total = m*n;
        
        int left = 0;
        int right = n-1;
        int top = 0;
        int down = m-1;
        
        
        while(result.size()!=total){
            
            // Left to right
            for(int c=left;c<=right;c++){
                result.push_back(matrix[top][c]);
            }
            
            // Top to down
            for(int r=top+1;r<=down;r++){
                result.push_back(matrix[r][right]);
            }
            
            if(top!=down){
                // Bottom Left to right
                for(int c=right-1;c>=left;c--){
                    result.push_back(matrix[down][c]);
                }
            }
            
            if(left!=right){
                // Left down to top
                for(int r=down-1;r>=top+1;r--){
                    result.push_back(matrix[r][left]);
                }
            }
            left++;
            right--;
            top++;
            down--;
        }
        return result;
        
    }
};