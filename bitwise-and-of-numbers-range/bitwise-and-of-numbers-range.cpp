class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int result = right;
        for(int i=left;i<right;i++){
            result = result&i;
            if(result==0) return result;
        }
        return result;
    }
};