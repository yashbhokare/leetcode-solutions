class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res= 0;
        int min = INT_MAX;
        for(int price:prices){
            if(price<min){
                min = price;
            }
            res = max(res,price-min); 
        }
        return res;
    }
};