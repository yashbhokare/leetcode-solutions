class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int f = binarySearch(nums,target,true);
        if(f==-1) return {-1,-1};
        int l = binarySearch(nums,target,false);
        return {f,l};
    }
    
    int binarySearch(vector<int>& nums,int target,bool firstOccurence){
        int start = 0;
        int end = nums.size()-1;
        int result = -1;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(nums[mid]==target){
                if(firstOccurence){
                    if(start==mid || nums[mid-1]!=target){
                        return mid;
                    }
                    end= mid-1;
                }
            else {
                if(end==mid || nums[mid+1]!=target){
                    return mid;
                }
                start=mid+1;
            }
            }
        else if(nums[mid]<target){
            start=mid+1;
        }else {
            end = mid-1;
        }
            
        }
        return result;
    }
};