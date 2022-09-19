class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,int> mapper;
        vector<vector<string>> result;
        int index= 0;
        for(auto s:strs){
            string temp = s;
            sort(begin(temp),end(temp));
            if(mapper.find(temp)!=mapper.end()){
                result[mapper[temp]].push_back(s);
            }else {
                result.push_back({s});
                mapper[temp] = index;
                index++;
            }
        }
        return result;
    }
};