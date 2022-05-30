class Solution {
public:
    int nc,nr = 0;
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        nr = matrix.size();
        nc = matrix[0].size();
        int left = 0;
        int right = nc-1;
        int up = 0;
        int down = nr-1;
        while(result.size() < nr*nc ){
            for(int c = left;c<=right;c++){
                result.push_back(matrix[up][c]);
            }
            for(int r = up+1;r<=down;r++){
                result.push_back(matrix[r][right]);
            }
            
            if(up!=down){
                for(int c = right-1;c>=left;c--){
                    result.push_back(matrix[down][c]);
                }
            }

            if(left!=right){
                for(int r=down-1;r>up;r--){
                    result.push_back(matrix[r][left]);
                }
            }
            left++;
            up++;
            right--;
            down--;
        }
        return result;
    }

    
};