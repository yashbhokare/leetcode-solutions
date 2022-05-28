class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int result =0;
        for(auto& num:nums){
            if(countLength(num)%2==0) result++;
        }
        return result;
    }
    
    int countLength(int num){
        int count=0;
        while(num!=0){
            num=num/10;
            count++;
        }
        return count;
    }
};