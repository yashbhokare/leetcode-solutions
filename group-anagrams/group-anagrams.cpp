class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int index = 0;
        unordered_map<string,int> strMap;
        vector<vector<string>> result;
        for(int i=0;i<strs.size();i++){
            string value = strs[i];
            // char charArray[value.length()+1];
            // strcpy(charArray,value.c_str());
            // sort(charArray,charArray+strlen(charArray));
            // cout<<charArray;
            sort(value.begin(),value.end());
            const auto it = strMap.find(value);
            if(it == strMap.end()){
                strMap.insert({value,index});
                result.push_back({strs[i]});
                index++;
            } else{
                const int fecthIndex = it->second;
                result[fecthIndex].push_back(strs[i]);
            }
            
            // cout<<value;
        }
        return result;
    }
};