class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
    for(int i=1;i<n;i++){
                if(checkForZero(i) && checkForZero(n-i)){
                    return {i,n-i};
                }
    }
        return {};
    }
    bool checkForZero(int val){
        while(val){
            int digit = val%10;
            if(digit==0) return false;
            val=val/10;
        }
        return true;
    }
};