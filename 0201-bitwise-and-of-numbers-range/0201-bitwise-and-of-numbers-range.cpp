class Solution {
public:
    // int rangeBitwiseAnd(int left, int right) {
    //     int result = right;
    //     for(int i=left;i<right;i++){
    //         result = result&i;
    //         if(result==0) return result;
    //     }
    //     return result;
    // }
    int rangeBitwiseAnd(int m, int n) {
        int shift = 0;
        // find the common 1-bits
        while (m < n) {
          m >>= 1;
          n >>= 1;
          ++shift;
        }
        return m << shift;
  }
};