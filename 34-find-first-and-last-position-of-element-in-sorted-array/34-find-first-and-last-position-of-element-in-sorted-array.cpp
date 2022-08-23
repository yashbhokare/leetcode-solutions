class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstOccurence = binarySearch(nums,target,true);
        if(firstOccurence==-1) return {-1,-1};
        int lastOccurence = binarySearch(nums,target,false);
        return {firstOccurence,lastOccurence};
    }
    
    int binarySearch(vector<int>& nums, int target, bool isFirst){
        int start = 0;
        int end = nums.size()-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            
            if(nums[mid]==target){
                if(isFirst){
                    if(mid==start || nums[mid]>nums[mid-1]){
                        return mid;
                    }else {
                        end = mid-1;
                    }
                }else {
                    if(mid==end || nums[mid]<nums[mid+1]){
                        return mid;
                    }else {
                        start = mid+1;
                    }
                }
            }else if(nums[mid]<target){
                start++;
            }else {
                end--;
            }
        }
        return -1;
    }
};