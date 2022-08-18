class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int size= arr.size();
        unordered_map<int,int> mapper;
        vector<int> values;
        int index=0;
        for(auto num:arr){
            if(mapper.find(num)==mapper.end()){
                mapper[num]=index;
                values.push_back(1);
                index++;
            }else {
                values[mapper[num]]++;
            }
        }
        sort(values.begin(),values.end(),greater());
        
        int ans = 1;
        int totalCount = 0;
        for(auto val:values){
            totalCount = totalCount + val;
            if(totalCount>=size/2){
                return ans;
            }
            ans++;
        }
        return ans;
       
    }
};