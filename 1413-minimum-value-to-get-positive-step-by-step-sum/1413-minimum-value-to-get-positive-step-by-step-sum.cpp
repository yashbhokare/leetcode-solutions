class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int minVal = 0;
        int total = 0;
        for(auto num:nums){
            total = num + total;
            if(total<1){
                int temp = 1 - total;
                minVal+=temp;
                total=1;
            }
        }
        return minVal==0 ? 1 : minVal;
    }
};