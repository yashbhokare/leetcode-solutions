class Solution {
public:
    bool isPowerOfFour(int n) {
        auto val = log(n)/log(2);
        double num = 2;
        auto d = fmod(val,num);
        cout<<d;
        if(d==0){
            return true;
        } 
    return false;
    }
};