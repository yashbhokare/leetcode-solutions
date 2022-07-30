class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> result;
        unordered_map<char,int> word2mapper;
        for(auto word:words2){
            unordered_map<char,int> tempMapper;
            for(auto ch:word){
                tempMapper[ch]++;
            }
            for(auto it=tempMapper.begin();it!=tempMapper.end();it++){
                if(word2mapper[it->first]<tempMapper[it->first]){
                    word2mapper[it->first] = tempMapper[it->first];
                }
            }
        }
        
        for(auto word:words1){
        int size = 0;
        unordered_map<char,int> word1mapper;
            for(auto ch:word){
                word1mapper[ch]++;
                 // cout<<ch<<" "<<word1mapper[ch]<<endl;
                if(word2mapper.find(ch)!=word2mapper.end() && word1mapper[ch]==word2mapper[ch]){
                    size++;
                }
                if(size==word2mapper.size()){
                    result.push_back(word);
                    break;
                }
            }
        }
        
        return result;
    }
};