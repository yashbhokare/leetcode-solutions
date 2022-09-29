class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        return findClosestElementsUsingBinarySearch(arr,k,x);
    }
    
    vector<int> findClosestElementsUsingBinarySearch(vector<int>& arr, int k, int x) {
        
        int n = arr.size();
        //Binary Search to find the closest element
        int left = 0;
        int right= n-1;
        while(left<right){
            int mid = (left+right)/2;
            if(arr[mid]>=x){
                right=mid;
            }else {
                left=mid+1;
            }
        }
        
        
        left = left-1;
      right = left+1;
        while((right-left-1)<k){
            
            if(left==-1){
                right++;
                continue;
            }
            
            if(right==n){
                left--;
                continue;
            }
            if(abs(x-arr[left])<=abs(x-arr[right])){
                left--;
            }else {
                right++;
            }
        }
        
        vector<int> result;
        for(int index=left+1;index<right;index++){
            result.push_back(arr[index]);
        }
        
        return result;

    }
    
    vector<int> findClosestElementsUsingHeap(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> max_heap;
        for(int i=arr.size()-1;i>=0;i--){
            int diff = abs(arr[i]-x);
            max_heap.push({diff,arr[i]});
            if(max_heap.size()>k){
                max_heap.pop();
            }
        }
        vector<int> result;
        while(!max_heap.empty()){
            result.push_back(max_heap.top().second);
            max_heap.pop();
        }
        sort(result.begin(),result.end());
        
        return result;
    }
};