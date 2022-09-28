class Solution {
public:
    vector<vector<int>> skip;
    unordered_set<int> visited;
    int numberOfPatterns(int m, int n) {
        skip.resize(10,vector<int>(10,0));
        skip[1][3] = 2;
        skip[3][1] = 2;
        skip[1][7] = 4;
        skip[7][1] = 4;
        skip[7][9] = 8;
        skip[9][7] = 8;
        skip[3][9] = 6;
        skip[9][3] = 6;
        skip[1][9] = 5;
        skip[9][1] = 5;
        skip[3][7] = 5;
        skip[7][3] = 5;
        skip[2][8] = 5;
        skip[8][2] = 5;
        skip[4][6] = 5;
        skip[6][4] = 5;
        
        int result = 0;
        for(int i=m;i<=n;i++){
            for(int num=1;num<=9;num++){
                visited.insert(num);
                result+=backTrack(num,i-1);
                visited.erase(num);
            }
        }
        return result;
        
    }
    
    int backTrack(int curr_num,int remain){
        // cout<<curr_num<<":"<<remain<<", ";
        if(remain<0) return 0;
        if(remain==0) return 1;
        visited.insert(curr_num);
        int ans = 0;
        for(int num=1;num<=9;num++){
            if(visited.find(num)==visited.end() && (skip[curr_num][num]==0 || visited.find(skip[curr_num][num])!=visited.end())){
                // cout<<num<<" ";
                // visited.insert(num);
                ans+=backTrack(num,remain-1);
              
            }
        }
        visited.erase(curr_num);
        return ans;
        
    }
    
    
};