class DetectSquares {
public:

    int cntPoints[1001][1001]  = {};
    vector<pair<int,int>> points;
    
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        int x = point[0];
        int y= point[1];
        cntPoints[x][y]++;
        points.push_back({x,y});
    }
    
    int count(vector<int> point) {
        int x1 = point[0], y1 = point[1], ans=0;
        for(auto& [x3,y3]:points){
            if(abs(x1-x3)==0 || abs(x1-x3)!=abs(y1-y3)) continue;
            ans+=cntPoints[x1][y3]*cntPoints[x3][y1];
        }
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */