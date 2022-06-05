class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        for(auto& asteroid:asteroids){
            if(stk.empty()) {
                stk.push(asteroid);
                continue;
            }
            if((asteroid<0 && stk.top()>0)){
                while(!stk.empty() && (abs(asteroid) > stk.top()) && asteroid*stk.top()<0){
                        stk.pop();
                }
                if(stk.empty()){
                    stk.push(asteroid);
                }else if(asteroid*stk.top()>0){
                    stk.push(asteroid);
                }else if(abs(asteroid)==stk.top()){
                    stk.pop();
                }
            
            }else {
                stk.push(asteroid);
            }
        }
        
        vector<int> res;
        while(!stk.empty()){
            res.insert(res.begin(),stk.top());
            stk.pop();
        }
        return res;
    }
};