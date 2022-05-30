class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len=nums.size();
        vector<int> left(len, 1);
        vector<int> right(len, 1);
        vector<int> result(len, 0);
        for(int i=1; i<len; i++)  left[i]=left[i-1]*nums[i-1];
        for(int i=len-2; i>=0; i--)  right[i]=right[i+1]*nums[i+1];
        for(int i=0; i<len; i++) result[i]=left[i]*right[i];
        return result;

        // vector<int> result;
        // int product = 1;
        // bool zero = false;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i] == 0 && !zero){
        //         zero = true;
        //     } else {
        //         product = product * (nums[i]);
        //     }
        // }
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i] == 0){
        //         result.push_back(product);
        //     }else if(zero) {
        //         result.push_back(0);
        //     } 
        //     else {
        //         result.push_back(product/nums[i]);
        //     }
        // }
        // return result;
    }
};