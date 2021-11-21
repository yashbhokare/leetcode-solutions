class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        if(arr.size()==1) return arr;
        int n = arr.size() -1;
        int swapIndex = 0;
        for(int i=n;i>0;i--){
            if(arr[i-1] > arr[i]){
                swapIndex = i-1;
                break;
            }
        }
        int swapValue = arr[swapIndex];
        cout<<swapIndex;
        int nextSmallestValue = 0;
        int secondPos = 0;
        for(int i=swapIndex+1;i<=n;i++){
            if(arr[i] > nextSmallestValue && arr[i] < swapValue){
                secondPos = i;
                nextSmallestValue = arr[i];
            }
        }
        swap(arr[swapIndex],arr[secondPos]);
        return arr;
    }
};