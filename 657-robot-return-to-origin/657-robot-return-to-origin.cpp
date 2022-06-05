class Solution {
public:
    bool judgeCircle(string moves) {
        vector<vector<int>> dir={
            {1,0},
            {0,1},
            {-1,0},
            {0,-1}
        };
        

        int x=0,y=0;
        int xDir,yDir;
        for(auto& move:moves){
            if(move=='U'){
                xDir = dir[0][0];
                yDir = dir[0][1];
            }
            if(move=='R'){
                xDir = dir[1][0];
                yDir = dir[1][1];
            }
            if(move=='D'){
                xDir = dir[2][0];
                yDir = dir[2][1];
            }
            if(move=='L'){
                xDir = dir[3][0];
                yDir = dir[3][1];
            }
            x+=xDir;
            y+=yDir;
            
        }
        return x==0 && y==0;
    }
};