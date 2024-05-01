class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> stk;
        int n=temperatures.size();
        vector<int> result(n);
        for(int i=n-1;i>=0;i--){
            int currTemp=temperatures[i];
            while(!stk.empty() && stk.top().first<=currTemp){
                stk.pop();
            }
            if(stk.empty()){
                result[i]=0;
            }else {
                result[i]=stk.top().second-i;
            }
            stk.push({currTemp,i});
        }
        return result;
    }
};