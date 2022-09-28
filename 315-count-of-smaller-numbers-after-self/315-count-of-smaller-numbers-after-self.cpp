class Solution {
public:
     vector<int> result;
    // Using Merge sort
    vector<int> countSmaller(vector<int>& nums) {
        result.resize(nums.size(),0);
        vector<pair<int,int>> new_nums;
        
        for(int i=0;i<nums.size();i++){
            new_nums.push_back({nums[i],i});
        }
        
        merge_sort(new_nums,0,new_nums.size()-1);
        // for(auto num:new_nums){
        //     cout<<num.first<<" ";
        // }
        return result;
    }
    
    void merge_sort(vector<pair<int,int>>& new_nums, int left,int right){
        if(left>=right){
            return;
        }
        
        int mid = left + (right-left)/2;
        merge_sort(new_nums,left,mid);
        merge_sort(new_nums,mid+1,right);
        merge(new_nums,left,mid,right);
    }
    
    void merge(vector<pair<int,int>>& new_nums, int left,int mid,int right){
        vector<pair<int,int>> merged;
        int i = left;
        int j = mid+1;
        
        int num_of_values_less = 0;
        while(i<=mid && j<=right){
            if(new_nums[i].first > new_nums[j].first){
                merged.push_back(new_nums[j]);
                num_of_values_less++;
                j++;
            }else {
                int actual_index = new_nums[i].second;
                result[actual_index]+=num_of_values_less;
                merged.push_back(new_nums[i]);
                i++;
            }
        }
        
        while(i<=mid) {
            int actual_index = new_nums[i].second;
            result[actual_index]+=num_of_values_less;
            merged.push_back(new_nums[i]);
            i++;
        }
        
        while(j<=right){
            merged.push_back(new_nums[j]);
            j++;
        }
        
        int index=0;
        for(int i=left;i<=right;i++){
            new_nums[i] = merged[index++];
        }
    }
    
    
    
};