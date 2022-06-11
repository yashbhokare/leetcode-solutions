class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> minHeap;
        for(auto num:nums){
            if(minHeap.size()>=k && minHeap.top()<num){
                minHeap.pop();
                minHeap.push(num);
            }else if(minHeap.size()<k){
                minHeap.push(num);
            }
        }
        return minHeap.top();
    }
};