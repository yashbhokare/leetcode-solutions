class Solution {
public:
    int hammingWeight(uint32_t n) {
        int mask = 1;
        int count = 0;
        int index=0;
        while(index++<32){
            count+=n&mask;
            n>>=1;
        }
        return count;
    }
};