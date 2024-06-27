class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int last=arr.size()-1;
        int maxElement = -1;
        while(last>=0){
            int num=arr[last];
            arr[last] = maxElement;
            maxElement = max(num,maxElement);
            last--;
        }
        return arr;
    }
};