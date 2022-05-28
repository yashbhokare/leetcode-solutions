class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        return replaceElementsWithNewArray(arr);
        int prev=arr[arr.size()-1];
        arr[arr.size()-1]=-1;
        for(int i=arr.size()-2;i>=0;i--){
            int temp = max(arr[i+1],prev);
            prev= arr[i];
            arr[i] = temp;
        }
        return arr;
    }
    
    vector<int> replaceElementsWithNewArray(vector<int>& arr){
        vector<int> result(arr.size());
        result[arr.size()-1]=-1;
        for(int i=arr.size()-2;i>=0;i--){
            result[i]=max(arr[i+1],result[i+1]);
        }
        return result;
    }
};