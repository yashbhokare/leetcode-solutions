class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=binary_search(nums,target,true);
        if(first==-1) return {-1,-1};
        int last = binary_search(nums,target,false);
        return {first,last};
    }
    
    int binary_search(vector<int>& nums,int target,bool is_first_occurance){
        int start=0;
        int end = nums.size()-1;
        
        while(start<=end){
            int mid = start+(end-start)/2;
            if(nums[mid]==target){
                if(is_first_occurance){
                    if((mid>0 && nums[mid-1]!=nums[mid]) || start==mid){
                        return mid;
                    }else {
                        end = mid-1;
                    }
                }else {
                    if((mid<nums.size()-1 && nums[mid+1]!=nums[mid]) || end==mid){
                        return mid;
                    }else {
                        start = mid+1;
                    }
                }
            }else if(nums[mid]>target){
                end = mid-1;
            }else {
                start = mid+1;
            }
        }
        return -1;
    }
};