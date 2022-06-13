class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result=0;
        int minVal = INT_MAX;
        for(auto price:prices){
            if(price<minVal){
                minVal=price;
            }else {
                result = max(result,price-minVal);
            }
        }
        return result;
    }
};