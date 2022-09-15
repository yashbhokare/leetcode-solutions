// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         for(int i=0;i<nums.size();i++){
//             int minElem = INT_MAX;
//             int minIndex = i; 
//             for(int j=i;j<nums.size();j++){
//                 if(nums[j]<minElem){
//                     minElem = nums[j];
//                     minIndex = j;
//                 }
//             }
//             swap(nums[i],nums[minIndex]);
//         }
//     }
// };
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int startIndex=0;
        int lastIndex = nums.size()-1;
        int i=0;
        while(i<=lastIndex){
            if(nums[i]==0) swap(nums[i++],nums[startIndex++]);
            else if(nums[i]==2) swap(nums[i],nums[lastIndex--]);
            else i++;
        }
    }
};