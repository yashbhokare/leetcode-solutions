class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        int count = 0;
        int startPos = 0;
        for(int i=0;i<cost.size();i++){
            total+= gas[i]-cost[i];
            count+=gas[i]-cost[i];
            // cout<<count;
            if(count<0){
                // cout<<count;
                count=0;
                startPos= i+1;
            }
        }
        // cout<<total;
        if(total>=0) return startPos;
        return -1;
    }
};