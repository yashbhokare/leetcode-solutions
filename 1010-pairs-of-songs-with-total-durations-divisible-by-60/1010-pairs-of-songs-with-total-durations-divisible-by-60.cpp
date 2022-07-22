class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int result = 0;
        unordered_map<int,int> mapper;
        for(auto t:time){
            int timeVal = t%60;
            int remainingTime =  60-timeVal;
            if(timeVal==0){
                result+=mapper[timeVal];
            }
            else if(mapper.find(remainingTime)!=mapper.end()){
                result+=mapper[remainingTime];
            }
            // if(timeVal==0) mapper[t]++;
            mapper[timeVal]++;
        }
        return result;
    }
};