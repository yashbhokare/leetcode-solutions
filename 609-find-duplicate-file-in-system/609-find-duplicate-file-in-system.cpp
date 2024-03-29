class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string>> mapper;
        for(auto path:paths){
            // int index = path.find_first_of(" ");
            string root;
            // root=path.substr(0,index);
            // root.push_back('/');
            // path = path.substr(index);
            stringstream ss(path);
            ss>>root;
            root.push_back('/');
            string word;
            while(ss>>word){
                int firstBracket = word.find_first_of('(');
                int lastBracket = word.find_first_of(')');
                string fileName=word.substr(0,firstBracket);
                string fileContent = word.substr(firstBracket+1,lastBracket);
                mapper[fileContent].push_back(root+fileName);
            } 
        }
        vector<vector<string>> result;
        for(auto it=mapper.begin();it!=mapper.end();it++){
            if(it->second.size()>1)
            result.push_back(it->second);
        }
        return result;
    }
};