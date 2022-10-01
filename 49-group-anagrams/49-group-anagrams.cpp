class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,int> mapper;
        vector<vector<string>> result;
        int index=0;
        for(auto s:strs){
            string temp = s;
            sort(s.begin(),s.end());
            if(mapper.find(s)==mapper.end()){
                mapper[s] = index;
                result.push_back({temp});
                index++;
            }else {
                result[mapper[s]].push_back(temp);
            }
                
        }
        return result;
    }
};