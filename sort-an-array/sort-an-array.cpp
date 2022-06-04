class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // mergeSort(nums,0,nums.size()-1);
        quickSort(nums,0,nums.size()-1);
        return nums;
    }
    
    void quickSort(vector<int>& nums,int low,int high){
        if(low>=high) return; 
        int pivotElement = nums[low];
        int start = low;
        int end = high;
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
    
    void mergeSort(vector<int>& nums,int low,int high){
        if(low>=high) return;
        int mid = (low+high)/2;
        mergeSort(nums,low,mid);
        mergeSort(nums,mid+1,high);
        merge(nums,low,mid,high);
    }
    
    void merge(vector<int>& nums,int low,int mid,int high){
        int left = low;
        int leftMax = mid;
        int right = mid+1;
        int rightMax = high;
        vector<int> mergedList;
        while(left<=leftMax && right<=rightMax){
            if(nums[left]<=nums[right]){
                mergedList.push_back(nums[left]);
                left++;
            }else{
                mergedList.push_back(nums[right]);
                right++;
            }
        }
        while(left<=leftMax){
            mergedList.push_back(nums[left]);
            left++;
        }
        
        while(right<=rightMax){
            mergedList.push_back(nums[right]);
            right++;
        }
        for(int i =0;i<mergedList.size();i++){
            nums[low+i]= mergedList[i];
        }
    }
};