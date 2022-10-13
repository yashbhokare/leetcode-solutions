class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls= 0;
        int cows = 0;
        unordered_map<char,int> secret_map;
        for(auto ch:secret) secret_map[ch]++;
        for(int i=0;i<guess.size();i++){
            if(secret[i]==guess[i]){
                bulls++;
                secret_map[guess[i]]--;
                guess[i] ='X';
            }
        }
        for(int i=0;i<guess.size();i++){
            if(secret_map[guess[i]]>0){
                cows++;
                secret_map[guess[i]]--;
            }
        }

        string result = to_string(bulls)+"A"+to_string(cows)+"B";
        return result;
    }
};