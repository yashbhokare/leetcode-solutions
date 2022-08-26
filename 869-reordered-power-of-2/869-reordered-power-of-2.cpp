class Solution {
public:
    
    bool reorderedPowerOf2(int n) {
        string val = to_string(n);
        return permutations(val,0);
        return true;
    }
    
    bool permutations(string s,int index){
        if(s[0]=='0') return false;

        if(index==s.size()){
            if(isPowerOfTwo(stoi(s))==1){
                return true;
            }
            return false;
        }
        
        for(int i=index;i<s.size();i++){
            swap(s[i],s[index]);
            if(permutations(s,index+1)) return true;
            swap(s[i],s[index]);
        }
        return false;
    }
    
    bool isPowerOfTwo(int n) {
        if (n == 0) return false;
        while (n % 2 == 0) n /= 2;
        return n == 1;
    }
    
  //   bool isPowerOfTwo(int n) {
  //   if (n == 0) return false;
  //   long x = n;
  //   return (x & (-x)) == x;
  // }
};