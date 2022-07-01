class Solution {
public:
    static int comparator(vector<int> a, vector<int> b){
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),comparator);
        int result = 0;
        for(auto box:boxTypes){
            int boxCount = min(truckSize, box[0]);
            result += boxCount * box[1];
            truckSize -= boxCount;
            if (truckSize == 0) break;
        }
        return result;
    }
};