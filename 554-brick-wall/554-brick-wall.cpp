class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        return hashMap(wall);
    }   
    
    int bruteForces(vector<vector<int>>& wall){
        int width = accumulate(wall[0].begin(),wall[0].end(),0);
        int height = wall.size();
        vector<int> pos(height+1,0);
        int minVal = height;
        for(int stepSize=1;stepSize<width;stepSize++){
            int count=0;
            for(int row=0;row<height;row++){
                int remaining = wall[row][pos[row]]-1;
                if(remaining==0){
                    pos[row]++;
                }else {
                    wall[row][pos[row]] = remaining;
                    count++;
                }
            }
            minVal = min(minVal,count);;
        }
        return minVal;
    }
    
    int hashMap(vector<vector<int>>& wall){
        unordered_map<int,int> mapper;
        int maxNumberOfGaps = 0;
        for(int r=0;r<wall.size();r++){
            int nextGap = 0;
            for(int c=0;c<wall[r].size()-1;c++){
                nextGap = nextGap+wall[r][c];
                mapper[nextGap]++;
                maxNumberOfGaps = max(maxNumberOfGaps,mapper[nextGap]);
            }
        }
        return wall.size()-maxNumberOfGaps;
    }
};