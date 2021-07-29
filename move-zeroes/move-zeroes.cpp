class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroCount = 0;
        auto it=nums.begin();
        while(it !=nums.end()){
            if(*it == 0){
                nums.erase(it);
                zeroCount++;
            }else{
                ++it;
            }
            if(nums.empty()){
                break;
            }
        }
        nums.insert(nums.end(),zeroCount,0);
    }
};

// Better Approach
void moveZeroes1(vector<int>& nums) {
    int lastNonZeroFoundAt = 0;
    // If the current element is not 0, then we need to
    // append it just in front of last non 0 element we found. 
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            nums[lastNonZeroFoundAt++] = nums[i];
        }
    }
 	// After we have finished processing new elements,
 	// all the non-zero elements are already at beginning of array.
 	// We just need to fill remaining array with 0's.
    for (int i = lastNonZeroFoundAt; i < nums.size(); i++) {
        nums[i] = 0;
    }
}

void moveZeroes2(vector<int>& nums) {
    for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++) {
        if (nums[cur] != 0) {
            swap(nums[lastNonZeroFoundAt++], nums[cur]);
        }
    }
}