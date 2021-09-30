typedef pair<int, int> pi;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(int num : nums){
            map[num]++;
        }
        
        // vector<int> res;
        // // pair<first, second>: first is frequency,  second is number
        // priority_queue<pair<int,int>> pq; 
        // for(auto it = map.begin(); it != map.end(); it++){
        //     pq.push(make_pair(it->second, it->first));
        //     if(pq.size() > (int)map.size() - k){
        //         res.push_back(pq.top().second);
        //         pq.pop();
        //     }
        // }

        priority_queue<pi,vector<pi>,greater<pi>> pq1; 
        for(auto it = map.begin(); it != map.end(); it++){
            pq1.push(make_pair(it->second, it->first));
            if(pq1.size() > k){
                pq1.pop();
            }
        }
        
        vector<int> res2;
        while(k--){
            res2.insert(res2.begin(),pq1.top().second);
            pq1.pop();
        }
        return res2;
    }
};