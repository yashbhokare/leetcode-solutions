class Solution {
public:
    static bool comparator(int v1, int v2){
        bitset<16> b1(v1);
        bitset<16> b2(v2);
        if(b1.count()==b2.count()){
            return v1 < v2;
        } else {
            return b1.count() < b2.count();
        }
    }

    vector<int> sortByBits(vector<int>& arr) {
        
        sort(arr.begin(),arr.end(),comparator);
        return arr;
    }
};