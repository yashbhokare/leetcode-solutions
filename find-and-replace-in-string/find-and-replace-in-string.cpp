class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int index=0;
        map<int,pair<int,string>> mapper;
        for(int i=0;i<indices.size();i++){
            index = indices[i];
            if(s.substr(index,sources[i].size())==sources[i]){
                mapper[index] = {sources[i].size(),targets[i]};
            }
        }
        index = 0;
        for(auto it=mapper.begin();it!=mapper.end();it++){
            int currIndex= it->first + index;
            // cout<<currIndex<<" ";
            s.replace(currIndex,it->second.first,it->second.second);
            index+= it->second.second.size()-it->second.first;
            // cout<<index<<endl;
        }
        
        return s;
    }
};