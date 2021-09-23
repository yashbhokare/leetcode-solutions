class Solution {
public:
    string reverseStr(string s, int k) {
        if(k == s.size() || k > s.size()){
            return reverseString(s,0,s.size() - 1);
        }
         k = k % s.size();
        for(int i=0;i<s.size();){
            if(i+k-1 < s.size()){
                s= reverseString(s,i,i+k-1);
            } else {
                s = reverseString(s,i,s.size() - 1);
            }
            
            i = i + 2*k;
        }
        return s;
    }
    
    string reverseString(string s,int start,int last){
        while(start< last){
            swap(s[start],s[last]);
            start++;
            last--;
        }
        return s;
    }
};