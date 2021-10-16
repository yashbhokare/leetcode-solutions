class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT_MIN;
        vector<pair<int,int>> resultArray;
        
        int current = nums[0];
        int maxVal = nums[0];
        int len = 0;
        int curIndex = 0;
        int maxIndex = 0;
        for(int i=1;i<nums.size();i++){
//             if(nums[i]> nums[i]+current){

//                 curIndex = i;
//                 current = nums[i];
//             } else {
//                 current = nums[i]+current;
//             }
                current = max(nums[i],nums[i]+current);
            

//             if(current > maxVal){
//                 maxVal = current;
//                 maxIndex = i;
//             }
                maxVal = max(current,maxVal);
           } 
        
         // cout<<"Cur Val Index:"<<curIndex<<endl;
         // cout<<"Max Val Index:"<<maxIndex<<endl;
        
        // return maxVal;
        // BRUTE FORCE
        // int ans = 0;
        // int money = 7;
        // for(int i=0;i<nums.size();i++){
        //     int sum = 0;
        //     for(int j =i;j<nums.size();j++){
        //         sum = sum + nums[j];
        //         if(sum <= money) {
        //             // cout<<"Sum"<<sum;
        //             // cout<<"Cur Val Index:"<<i<<endl;
        //             // cout<<"Max Val Index:"<<j<<endl;
        //             ans = max(ans,j-i);
        //         }
        //         result = max(sum,result);
        //     }
        // }
        // if(ans) cout<<ans+1;
        // else cout<<0;
        // cout<<"Answer:"<<ans+1;
//         for(int i=1;i<=nums.size();i++){

//             for(int j=0;j<=nums.size()-i;j++){
//                 int sum = 0;
//                 for(int k=j;k<j+i;k++){
//                     sum = sum + nums[k];
//                 }
//                 result = max(sum,result);

//             }
//         }
        return maxVal;
    }
};