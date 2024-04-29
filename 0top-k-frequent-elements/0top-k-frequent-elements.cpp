class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mapper;
        for(auto num:nums) mapper[num]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
        
        for(auto it=mapper.begin();it!=mapper.end();it++){
            minHeap.push({it->second,it->first});
            if(minHeap.size()>k) minHeap.pop();
        }
        
        vector<int> result;
        while(!minHeap.empty()){
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return result;
    }
};