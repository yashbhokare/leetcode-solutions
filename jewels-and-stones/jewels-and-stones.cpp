class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> uSet(jewels.begin(),jewels.end());
        int count = 0;
        for(auto ch:stones){
            if(uSet.find(ch)!=uSet.end()){
                count++;
            }
        }
        return count;
    }
};