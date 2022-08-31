class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int rowMax = mat.size();
        int colMax = mat[0].size();

        unordered_map<int,priority_queue<int,vector<int>,greater<int>>> mapper;
        // priority_queue<int,vector<int>,greater()> minHeap;
        
        for(int r=0;r<rowMax;r++){
            for(int c=0;c<colMax;c++){
                mapper[r-c].push(mat[r][c]);
            }
        }
        
        for(int r=0;r<rowMax;r++){
            for(int c=0;c<colMax;c++){
                mat[r][c] = mapper[r-c].top();
                mapper[r-c].pop();
                // mapper[r-c].push(mat[r][c]);
            }
        }
        return mat;
    }
};