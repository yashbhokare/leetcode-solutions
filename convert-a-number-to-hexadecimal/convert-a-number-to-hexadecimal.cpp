const string HEX = "0123456789abcdef";
class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        string result;
        int count = 0;
        while (num && count++ < 8) {
            // cout<<(num & 0xf)<<endl;
            result = HEX[(num & 15)] + result;
            // cout<<result<<endl;
            num >>= 4;
        }
        return result;
    }
};