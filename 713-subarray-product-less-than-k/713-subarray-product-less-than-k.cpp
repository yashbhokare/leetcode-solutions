class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int prod = 1, ans = 0, left = 0;
        for (int right = 0; right < nums.size(); right++) {
            prod = prod*nums[right];
            while (prod >= k) {
                prod = prod/nums[left++];
            }
            ans += right - left + 1;
        }
        return ans;
    }
};

// TLE for Recursion
// class Solution {
// public:
//     vector<int> numbers;
//     int K=0;
//     int result=0;
//     unordered_map<int,int> mapper;
//     int numSubarrayProductLessThanK(vector<int>& nums, int k) {
//         numbers= nums;
//         K=k;
//         for(int i=0;i<nums.size();i++){
//             recursion(i,1);
//         }

//         return result == 0 ? result : result-nums.size();
//     }
    
//     void recursion(int index,int total){
//         if(total<K){
//             result++;
//         }else {
//             return;
//         }
        
//         if(index>numbers.size()-1) return;
        
//         recursion(index+1,total*numbers[index]);
//     }
// };