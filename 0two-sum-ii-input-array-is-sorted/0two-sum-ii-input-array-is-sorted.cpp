class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> map;
        for(int i=0;i<numbers.size();i++){
            int diff=target-numbers[i];
            auto it=map.find(diff);
            if(it!=map.end()) return {it->second+1,i+1};
            map.insert({numbers[i],i});
        }
        return {};
    }
};