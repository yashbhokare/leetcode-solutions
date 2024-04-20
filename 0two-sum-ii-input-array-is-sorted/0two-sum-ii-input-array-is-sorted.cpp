class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low=0;
        int high=numbers.size()-1;
        while(low<high){
            int sum=numbers[low]+numbers[high];
            if(sum==target) return {low+1,high+1};
            else if(sum>target) high--;
            else low++;
        }
        return {};
    }
    // vector<int> twoSum(vector<int>& numbers, int target) {
    //     unordered_map<int,int> map;
    //     for(int i=0;i<numbers.size();i++){
    //         int diff=target-numbers[i];
    //         auto it=map.find(diff);
    //         if(it!=map.end()) return {it->second+1,i+1};
    //         map.insert({numbers[i],i});
    //     }
    //     return {};
    // }
};