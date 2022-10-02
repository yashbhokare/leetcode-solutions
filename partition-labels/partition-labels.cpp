class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> mapper;
        vector<int> ans;
        int index = 0;
        vector<vector<int>> time;
        for(int i=0;i<s.size();i++){
            char c = s[i];
            if(mapper.find(c) == mapper.end()){
                mapper.insert({c,index});
                time.push_back({i,i});
                index++;
            } else {
                int timeIndex = mapper[c];
                time[timeIndex][1] = i;
            }
        }
        sort(time.begin(),time.end());
        vector<vector<int>> result;
        int startTime = time[0][0];
        int endTime = time[0][1];
        for(int i=1;i<time.size();i++){
            if(time[i][0]<endTime){
                endTime = max(endTime,time[i][1]);
            }else {
                result.push_back({startTime,endTime});
                startTime = time[i][0];
                endTime = time[i][1];
            }
        }
        result.push_back({startTime,endTime});

        for(int i=0;i<result.size();i++){
            cout<<result[i][0]<<":"<<result[i][1]<<endl;
            ans.push_back(result[i][1] - result[i][0]+1);
        }
        return ans;
    }
};