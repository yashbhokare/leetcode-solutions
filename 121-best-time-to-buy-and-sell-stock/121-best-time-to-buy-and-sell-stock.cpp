class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxValue = 0;
        int minValue=prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]<minValue){
                minValue = prices[i];
            }else {
                maxValue = max(maxValue,prices[i]-minValue);
            }
        }
        return maxValue;
    }
};