class Solution {
public:
    string reverseWords(string s) {
        // string result = "";
        vector<int> indexes;
        indexes.push_back(-1);
        for(int i=0;i<s.size();i++){
            if(s[i]==' ') indexes.push_back(i);
        }
        indexes.push_back(s.size());
        for(int i=1;i<indexes.size();i++){
            int start = indexes[i-1]+1;
            int end = indexes[i]-1;
            swapString(s,start,end);
        }
        return s;
    }
    
    void swapString(string& s,int start,int end){
        while(start<=end){
            swap(s[start++],s[end--]);
        }
    }
};