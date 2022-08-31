class Solution {
public:
    int rMax,cMax;
    vector<vector<int>> dir = {
        {0,1},{1,0},{0,-1},{-1,0}
    };
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> result;
        
        rMax = heights.size();
        cMax = heights[0].size();
        
        vector<int> isPacific(rMax*cMax,0);
        vector<int> isAtlantic(rMax*cMax,0);
        
        // 1 = Possible
        //-1 = Not possible
        
        for(int r=0;r<rMax;r++){
            for(int c=0;c<cMax;c++){
                if(recPacific(r,c,isPacific,heights)==1 && recAtlantic(r,c,isAtlantic,heights)==1){
                     result.push_back({r,c});
                }
                // if(recAtlantic(r,c,isAtlantic,heights)==1){
                //      result.push_back({r,c});
                // }
                // int pos = r+c+(r*(cMax-1)); 
                // if(isPacific[pos]==1){
                //     result.push_back({r,c});
                // }
            }   
        }
        return result;
    }
    
    int recPacific(int r,int c,vector<int>& isPacific,vector<vector<int>>& heights){
        int pos = r+c+(r*(cMax-1));
        
        if(isPacific[pos]==1) return 1;
        if(isPacific[pos]==-1) return -1;
        
        if(r==0 || c==0){
            isPacific[pos] = 1;
            return isPacific[pos];
        }
        
        // Visited
        isPacific[pos] = -2;

        int result = 0;
        for(int d =0;d<dir.size();d++){
            int newR = r + dir[d][0];
            int newC = c + dir[d][1];
            int newPos =  newR+newC+(newR*(cMax-1));
            
            if(newR>=0 && newR<rMax && newC>=0 && newC<cMax && heights[newR][newC]<=heights[r][c]&& isPacific[newPos]!=-2 ) {
                int val = recPacific(newR,newC,isPacific,heights);
                if(val==1){
                    // cout<<pos;
                    result = 1;
                    break;
                }else if(val==-1){
                    result = -1;
                }
            }
        }
        
        isPacific[pos] = result;
        return isPacific[pos];
    }
    
    int recAtlantic(int r,int c,vector<int>& isAtlantic,vector<vector<int>>& heights){
        int pos = r+c+(r*(cMax-1));
        
        if(isAtlantic[pos]==1) return 1;
        if(isAtlantic[pos]==-1) return -1;
        
        if(r==rMax-1 || c==cMax-1){
            isAtlantic[pos] = 1;
            return isAtlantic[pos];
        }
        
        // Visited
        isAtlantic[pos] = -2;

        int result = 0;
        for(int d =0;d<dir.size();d++){
            int newR = r + dir[d][0];
            int newC = c + dir[d][1];
            int newPos =  newR+newC+(newR*(cMax-1));
            
            if(newR>=0 && newR<rMax && newC>=0 && newC<cMax && heights[newR][newC]<=heights[r][c]&& isAtlantic[newPos]!=-2 ) {
                int val = recAtlantic(newR,newC,isAtlantic,heights);
                if(val==1){
                    result = 1;
                    break;
                }else if(val==-1){
                    result = -1;
                }
            }
        }
        
        isAtlantic[pos] = result;
        return isAtlantic[pos];
    }
    
    
};