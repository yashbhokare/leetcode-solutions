class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> minHeap;
        for(int num:nums){
            minHeap.push(num);
            if(minHeap.size()>k) minHeap.pop();
        }
        return minHeap.top();
    }
    
    int quickSelect(vector<int>& nums, int k){
        int n = nums.size();
        int smallestPos = n-k;
        
        int left=0,right=n-1;
        int pivotIndex =-1;
        while(pivotIndex!=smallestPos){
            pivotIndex = left;
            left++;
            while(left<=right){
                if(nums[pivotIndex]>nums[left]){
                    swap(nums[pivotIndex],nums[left]);
                    pivotIndex = left;
                    left++;
                }else {
                    swap(nums[left],nums[right--]);
                }
            }
            if(pivotIndex==smallestPos) return nums[pivotIndex];
            if(pivotIndex<smallestPos) left = pivotIndex+1;
            else right=pivotIndex-1;
        }
        return nums[pivotIndex];
    }
};