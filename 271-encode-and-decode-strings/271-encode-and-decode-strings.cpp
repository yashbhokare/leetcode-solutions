class Codec {
public:
    char ch = (char)500;
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
       
        string result = "";
        for(auto s:strs){
            result = result + s + ch; 
        }
        result.substr(0,result.size()-3);
        return result;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> result;
        stringstream ss(s);
        string word;
        while(getline(ss,word,ch)){
            result.push_back(word);
        }
        return result;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));