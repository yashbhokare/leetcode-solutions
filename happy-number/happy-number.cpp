class Solution {
public:
    unordered_set<int> hashSet;
    bool isHappy(int n) {
        return sumOfSquaresOfNumber(n);
    }
    
    bool sumOfSquaresOfNumber(int val){
        if(val==1) return true;
        if(val<4) return false;
        int sum=0;
        while(val>0){
            int digit=val%10;
            sum+=digit*digit;
            val=val/10;
        }
        // Cycle has been formed
        if(hashSet.count(sum)>0) return false;
        hashSet.insert(sum);
        
        return sumOfSquaresOfNumber(sum);
    }
};