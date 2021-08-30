class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT_MIN;
        vector<pair<int,int>> resultArray;
        
        for(int i=0;i<nums.size();i++){
            int sum = 0;
            for(int j =i;j<nums.size();j++){
                sum = sum + nums[j];
                result = max(sum,result);
            }
        }
        
//         for(int i=1;i<=nums.size();i++){

//             for(int j=0;j<=nums.size()-i;j++){
//                 int sum = 0;
//                 for(int k=j;k<j+i;k++){
//                     sum = sum + nums[k];
//                 }
//                 result = max(sum,result);

//             }
//         }
        return result;
    }
};