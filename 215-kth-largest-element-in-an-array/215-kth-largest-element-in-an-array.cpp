class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> minHeap;
        for(int num:nums){
            minHeap.push(num);
            if(minHeap.size()>k) minHeap.pop();
        }
        return quickSelect(nums,k);
    }
    
    int quickSelect(vector<int>& nums, int k){
        int n = nums.size();
        int smallestPos = n-k;
        
        int left=0,right=n-1;
        int pivotIndex =-1;
        // display(nums);
        while(pivotIndex!=smallestPos){
            pivotIndex = left;
            int tempLeft = left+1;
            int tempRight = right;
            while(tempLeft<=tempRight){
                if(nums[pivotIndex]>nums[tempLeft]){
                    swap(nums[pivotIndex],nums[tempLeft]);
                    pivotIndex = tempLeft;
                    tempLeft++;
                }else {
                    swap(nums[tempLeft],nums[tempRight--]);
                }
            }
            // cout<<"Index:"<<nums[pivotIndex]<<endl;
            // display(nums);
            if(pivotIndex==smallestPos) return nums[pivotIndex];
            if(pivotIndex<smallestPos) left = pivotIndex+1;
            else right=pivotIndex-1;
        }
        return nums[pivotIndex];
    }
    
    void display(vector<int>& nums){
        for(int num:nums) cout<<num<<" ";
        cout<<endl;
    }
};