class Solution {
public:
    string reverseWords(string s) {
        int start=0;
        for(int i=0;i<=s.size();i++){
            if(i==s.size() || s[i]==' '){
                swapString(s,start,i-1);
                start=i+1;
            }
            
        }
        return s;
    }
    
    void swapString(string& s,int start,int end){
        while(start<=end){
            swap(s[start++],s[end--]);
        }
    }
};