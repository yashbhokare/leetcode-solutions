class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded_string = "";
        for(int i=0;i<strs.size();i++){
            string bits = bitset<8>(strs[i].size()).to_string();
            encoded_string+=bits+strs[i];
        }
        return encoded_string;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> decoded_array;
        // cout<<s<<endl;
        for(int i=0;i<s.size();){
            string bits = "";
            for(int j=i;j<i+8;j++){
                bits.push_back(s[j]);
            }
            i+=8;
            
            int size = bitset<8>(bits).to_ulong();
            string curr_string = "";
            for(int k=i;k<i+size;k++){
                curr_string.push_back(s[k]);
            }
            i+=size;
            // cout<<curr_string<<endl;
            decoded_array.push_back(curr_string);
            // int size = b.to_ulong();
            
        }
        return decoded_array;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));

// class Codec {
// public:
//     Using an ASCII char greater then 256
//     char ch = (char)500;
//     // Encodes a list of strings to a single string.
//     string encode(vector<string>& strs) {
       
//         string result = "";
//         for(auto s:strs){
//             result = result + s + ch; 
//         }
//         result.substr(0,result.size()-3);
//         return result;
//     }

//     // Decodes a single string to a list of strings.
//     vector<string> decode(string s) {
//         vector<string> result;
//         stringstream ss(s);
//         string word;
//         while(getline(ss,word,ch)){
//             result.push_back(word);
//         }
//         return result;
//     }
// };