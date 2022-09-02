// class Solution {
// public:
//     string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
//         int index=0;
//         map<int,pair<int,string>> mapper;
//         for(int i=0;i<indices.size();i++){
//             index = indices[i];
//             if(s.substr(index,sources[i].size())==sources[i]){
//                 mapper[index] = {sources[i].size(),targets[i]};
//             }
//         }
//         index = 0;
//         for(auto it=mapper.begin();it!=mapper.end();it++){
//             int currIndex= it->first + index;
//             s.replace(currIndex,it->second.first,it->second.second);
//             index+= it->second.second.size()-it->second.first;
//         }
        
//         return s;
//     }
// };

class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        vector<pair<int, int>> indicesInDescendingOrder;
        for(int i = 0; i < indices.size(); i++){
            indicesInDescendingOrder.push_back({indices[i], i});
        }
        
        sort(indicesInDescendingOrder.rbegin(), indicesInDescendingOrder.rend());
        
        for(int i = 0; i < indicesInDescendingOrder.size(); i++){
            int indicesIndex = indicesInDescendingOrder[i].first;
            int sourcesIndex = indicesInDescendingOrder[i].second;
            
            string sourcesStr = sources[sourcesIndex];
            if(s.substr(indicesIndex, sourcesStr.size()) == sourcesStr){
                 s.replace(indicesIndex,sourcesStr.size(),targets[sourcesIndex]);
                
//                 s = s.substr(0, indicesIndex) + targets[sourcesIndex] + s.substr(indicesIndex + sourcesStr.size());
            }
        }
        
        return s;
    }
};