class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string,int> mapper;
        int index=0;
        for(int i=0;i<strs.size();i++){
            string newS = strs[i];
            sort(newS.begin(),newS.end());
            auto it = mapper.find(newS);
            if(it == mapper.end()){
                mapper[newS] = index;
                res.push_back({strs[i]});
                index++;
            }else {
                res[it->second].push_back(strs[i]);
            }
        }
        return res;
    }
};