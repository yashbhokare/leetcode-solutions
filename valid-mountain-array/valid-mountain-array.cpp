class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        // Check for length
        if(arr.size()<3) return false;
        bool isIncreasing = false;
        bool isDecreasing = false;
        for(int i=1;i<arr.size();i++){
            if(arr[i]>arr[i-1] && !isDecreasing){
                isIncreasing=true;
            }else if(arr[i]<arr[i-1] && isIncreasing){
                isDecreasing= true;
            }else {
                return false;
            }
        }
        return isDecreasing;
    }
};