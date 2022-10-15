

class Solution {
public:
    void findSecretWord(vector<string>& words, Master& master) {
        auto wordDiff = [](const string_view lhs, const string_view rhs){
            return transform_reduce(begin(lhs), end(lhs), begin(rhs), 0, std::plus{}, [](auto lch, auto rch){return lch == rch;});
        };
        
        int res;
        string curr;
        
        auto zeroMatchCleanup = [&](){
            while (res == 0)
            {
                words.erase(std::remove_if(words.begin(), words.end(), [&](auto val){return wordDiff(curr, val);}), words.end());
                curr = words[words.size()/2];
                res = master.guess(curr);
            }
        };
        
        curr = words[words.size()/2];
        
        res = master.guess(curr);
        
        zeroMatchCleanup();
    
        while (res < 6)
        {
            words.erase(std::remove_if(words.begin(), words.end(), [&](auto val){
                return wordDiff(curr, val) != res || curr == val;
            }), words.end());
            
            curr = words[words.size()/2];
            
            res = master.guess(curr);

            zeroMatchCleanup();
            
        }
    }
};