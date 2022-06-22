class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums,0,nums.size()-1);
        return nums;
    }
    
    void quickSort(vector<int>& nums,int start,int end){
        if(start>=end) return;
        int pivotElement = nums[start];
        cout<<pivotElement<<" ";
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
        cout<<"Low:"<<low<<endl;
        quickSort(nums,start,low-1);
        quickSort(nums,low+1,end);
    }
};