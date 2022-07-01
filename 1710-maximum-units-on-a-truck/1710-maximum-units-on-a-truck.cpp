class Solution {
public:
    static int comparator(vector<int> a, vector<int> b){
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),comparator);
        int result = 0;
        for(auto box:boxTypes){
            if(truckSize-box[0] >= 0){
                result+=box[0]*box[1];
                truckSize-=box[0];
            }else if(truckSize!=0){
                result+=truckSize*box[1];
                break;
            }
            
            if(truckSize==0) return result;
        }
        return result;
    }
};