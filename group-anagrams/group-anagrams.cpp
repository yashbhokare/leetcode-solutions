class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,int> mapper;
        vector<vector<string>> result;
        int index = 0;
        for(int i=0;i<strs.size();i++){
            string val = strs[i];
            sort(val.begin(),val.end());
            
            auto it = mapper.find(val);
            // Value found
            if(it != mapper.end()){
                int indexVal = it->second;
                result[indexVal].push_back(strs[i]);
            }else {
                mapper.insert({val,index});
                result.push_back({strs[i]});
                index++;
            }
        }
        return result;
        
        // return result;
    }
};