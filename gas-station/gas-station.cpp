class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGasCount = 0;
        int currTank = 0;
        int startPos =0;
        for(int i=0;i<cost.size();i++){
            totalGasCount = totalGasCount + gas[i] - cost[i];
            currTank = currTank + gas[i] - cost[i];
            if(currTank < 0){
                currTank = 0;
                startPos = i +1;
            }
        }

        if(totalGasCount < 0 ){
            return -1;
        }
        return startPos;
    }
};