class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> set;
        int count=0;
        for(char ch:jewels) set.insert(ch);
        for(char s:stones){
            if(set.count(s)>0) count++;
        }
        return count;
    }
};