class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        // quickSort(nums,0,nums.size()-1);
        return nums;
    }
    
    void quickSort(vector<int>& nums,int start,int end){
        if(start>=end) return;
        // int pivotElement = nums[start];
        int low  = start;
        int high = end;
        while(low<high){
            if(nums[low]>nums[low+1]){
                swap(nums[low],nums[low+1]);
                low++;
            }else {
                swap(nums[low+1],nums[high]);
                high--;
            }
        }
        quickSort(nums,start,low-1);
        quickSort(nums,low+1,end);
    }
    
    void mergeSort(vector<int>& nums,int start,int end){
        if(start>=end) return;
        int mid = (start + end)/2;
        mergeSort(nums,start,mid);
        mergeSort(nums,mid+1,end);
        merge(nums,start,mid,end);
    }
    
    void merge(vector<int>& nums,int start,int mid,int end){
        int low1=start;
        int high1=mid;
        
        int low2 = mid+1;
        int high2=end;
        vector<int> mergedArray;
        
        while(low1<=high1 && low2<=high2){
            if(nums[low1]<nums[low2]){
                mergedArray.push_back(nums[low1]);
                low1++;
            }else {
                mergedArray.push_back(nums[low2]);
                low2++;
            }
        }
        // cout<<low1;
        while(low1<=high1) mergedArray.push_back(nums[low1++]);
        while(low2<=high2) mergedArray.push_back(nums[low2++]);
        int index=0;
        for(int i=start;i<=end;i++)
            nums[i] = mergedArray[index++];
    }
};