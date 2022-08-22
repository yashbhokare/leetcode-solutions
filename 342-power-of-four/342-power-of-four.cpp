class Solution {
public:
    bool isPowerOfFour(int n) {

        if(fmod(log(n)/log(2),2)==0){
            return true;
        }
        return false;
    }
};