class NumArray {
public:
    vector<int> new_nums;
    NumArray(vector<int>& nums) {
        new_nums.resize(nums.size());
        for(int i=0;i<nums.size();i++){
            if(i!=0) new_nums[i]=nums[i]+new_nums[i-1];
            else new_nums[i] = nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        if(left==0) return new_nums[right];
        else return new_nums[right]-new_nums[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */