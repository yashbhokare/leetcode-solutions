class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max= 0;
        int min = INT_MAX;
        for(int price:prices){
            if(price<min){
                min = price;
            }else if(price - min > max){
                max= price - min;
            }
        }
        return max;
    }
};