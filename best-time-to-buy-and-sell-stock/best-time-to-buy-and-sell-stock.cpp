class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int min_val = INT_MAX;
        for(auto price:prices){
            if(price<min_val){
                min_val = price;
            }else {
                max_profit = max(max_profit,price-min_val);
            }
        }
        return max_profit;
    }
};