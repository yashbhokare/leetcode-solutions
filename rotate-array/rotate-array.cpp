class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        cyclicRotation(nums,k);
        // reverseApproach(nums,k);
    }
    
    void reverseApproach(vector<int>& nums, int k){
        k=k%nums.size();
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
    
    void cyclicRotation(vector<int>& nums, int k){
        k=k%nums.size();
        int count=0;
        int size=nums.size();
        int start=0;
        while(count<size){
            int pos=start;
            int prevValue =nums[pos];
            do{
                int move=(pos+k)%nums.size();
                int currValue=nums[move];
                nums[move]=prevValue ;
                pos=move;
                prevValue =currValue;
                count++;
            }while(pos!=start);
            start++;
        }
    }
};