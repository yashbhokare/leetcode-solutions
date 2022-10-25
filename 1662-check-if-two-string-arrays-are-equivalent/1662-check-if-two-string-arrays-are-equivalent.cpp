class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i=0,j=0;
        int index1 = 0;
        int index2 = 0;
        int len1 = word1.size();
        int len2 = word2.size();
        while(index1<len1 && index2<len2){
            if(index1<len1 && word1[index1].size()==i){
                i=0;
                index1++;
            }
            if(index2<len2 && word2[index2].size()==j){
                j=0;
                index2++;
            }
            if(index1==len1 && index2==len2) return true;
            if(index1==len1 || index2==len2) return false;
            if(word1[index1][i++]!=word2[index2][j++]) return false;
        }
        
        return true;
        
    }
};