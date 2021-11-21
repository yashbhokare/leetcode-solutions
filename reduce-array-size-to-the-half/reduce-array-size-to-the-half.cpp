class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> mapper;
        vector<int> numCounts;
        int index = 0;
        for(int num:arr){
            if(mapper.find(num) == mapper.end()){
                mapper[num] = index;
                numCounts.push_back(1);
                index++;
            }else {
                numCounts[mapper[num]]++;
            }
        }
        sort(numCounts.begin(),numCounts.end(),greater<int>());
        int ans = 1,sum=0;
        int halfSize = arr.size()/2;
        for(int num:numCounts){
            sum = sum + num;
            if(sum >= halfSize){
                return ans;
            }
            ans++;
        }
        return ans;
    }
};