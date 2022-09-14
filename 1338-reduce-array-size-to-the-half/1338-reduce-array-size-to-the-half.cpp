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

// class Solution {
// public:
//     int minSetSize(vector<int>& arr) {
//         int n = arr.size();
//         int max = n/2;
        
//         unordered_map<int, int> mp;
//         for(int i=0; i<n; ++i) mp[arr[i]]++;
//         vector<int> bucket(n+1, 0);
//         for(auto& i: mp) bucket[i.second]++;
//         int sum = 0, ans = 0;
//         for(int i=n; i>=0; --i) {
//             if(bucket[i]!=0) {
//                 int x = (int) ceil(1.0*(n/2-sum)/i);
//                 sum+=i*bucket[i];
//                 ans+=min(x, bucket[i]);
//                 if(sum>=n/2) break;
//             }
//         }
//      return ans;
//     }
// };