class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
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