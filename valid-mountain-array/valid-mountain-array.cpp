class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if(n<3) return false;
        bool isIncreasing=false;
        bool isDecreasing = false;
        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1] && !isDecreasing){
                isIncreasing=true;
            }else if(arr[i]<arr[i-1]){
                isDecreasing=true;
            }else {
                return false;
            }
        }
        return isIncreasing && isDecreasing;
    }
};