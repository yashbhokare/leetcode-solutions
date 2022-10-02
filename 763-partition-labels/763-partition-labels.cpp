class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> mapper;
        vector<vector<int>> time;
        int index=0;
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            if(mapper.find(ch)==mapper.end()){
                mapper[ch]=index;
                time.push_back({i,i});
                index++;
            }else {
                time[mapper[ch]][1] = i;
            }
        }
        
        sort(time.begin(),time.end());
        vector<vector<int>> merged;
        // Merge sort
        for(auto t:time){
            if(!merged.empty() && merged.back()[1]>=t[0]){
                merged.back()[1] = max(merged.back()[1],t[1]);
            }else {
                merged.push_back(t);
            }
        }
        
        vector<int> result;
        for(auto m:merged){
            result.push_back(m[1]-m[0]+1);
        }
        return result;
    }
};