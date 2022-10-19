class Solution {
public:
     uint32_t reverseBits(uint32_t n) {
         return reverseBitsBitByBit(n);
     }
    
    uint32_t reverseBitsUsingBitSet(uint32_t n) {
        string res = bitset<32>(n).to_string();
        reverse(res.begin(),res.end());
        uint32_t r = bitset<32>(res).to_ulong();
        return r;
    }
    
    uint32_t reverseBitsBitByBit(uint32_t n) {
        uint32_t ret = 0, power = 31;
        while (n != 0) {
          ret += (n & 1) << power;
          n = n >> 1;
          power -= 1;
        }
        return ret;
    }
};