class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t mask = 1;
        int bits = 0;
        for(int i=0;i<32;i++){
            if((n & mask)!=0){
                bits++;
            }
            mask=mask<<1;
        }
        return bits;
    }
};