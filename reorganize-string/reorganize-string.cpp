class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> mapper;
        int max = 0;
        char letter = s[0];
        for(int i=0;i<s.size();i++){
            mapper[s[i]]++;
            if(mapper[s[i]] > max){
                max = mapper[s[i]];
                letter = s[i];
            }
        }
        
        if(max > (s.size()+1)/2) return "";
        
        string result(s.size(),' ');
        auto it = mapper[letter];
        int index = 0;
        while(mapper[letter]){
            result[index] = letter;
            mapper[letter] --;
            index  = index + 2 > s.size() - 1 ? 1 : index + 2;
        }
        mapper.erase(letter);
        for(auto it= mapper.begin();it!=mapper.end();it++){
            letter = it->first;
            while(mapper[letter]){
                result[index] = letter;
                mapper[letter] --;
                index  = index + 2 > s.size() - 1 ? 1 : index + 2;
            }
        }
        return result;
    }
};