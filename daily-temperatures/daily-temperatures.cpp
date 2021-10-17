class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stk;
        vector<int> result(temperatures.size(),0);
        int maxLen = temperatures.size()-1;
        stk.push(maxLen);
        
        for(int i = maxLen - 1;i>=0;i--){
            
            int temp = temperatures[i];
            
            while(!stk.empty() && temp >= temperatures[stk.top()]){
                stk.pop();
            }
            
            if(stk.size() > 0){
                result[i]= stk.top() - i;
            }
            stk.push(i);
            
        }
        return result;
    }
};