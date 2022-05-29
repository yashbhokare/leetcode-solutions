class Solution {
public:
    void swap(vector<int>& nums, int posA, int posB){
        int temp = nums[posA];
        nums[posA]= nums[posB];
        nums[posB] = temp;
    }
    
    void rotate(vector<int>& nums, int k) {
        // reverse(nums.begin(),nums.end());
        // reverse(nums.begin(),nums.begin()+k);
        // reverse(nums.begin()+k,nums.end());
        cyclicReplacements(nums,k);
        // reverseApproach(nums,k);
    }
    
    void cyclicReplacements(vector<int>& nums, int k){
        //Using Cyclic Replacements
            k = k % nums.size();
            int count = 0;
            for(int start=0; count <nums.size(); start++){
                int currrentPosition = start;
                int prevValue = nums[currrentPosition];
                do{
                    int nextPosition = (currrentPosition + k) % nums.size();
                    int temp = nums[nextPosition];
                    nums[nextPosition] = prevValue;
                    prevValue = temp;
                    currrentPosition = nextPosition;
                    count++;
                }while(currrentPosition!=start);
            }   
    }
    
    void reverseApproach(vector<int>& nums, int k){
        // Using Reverse
        k = k % nums.size();
        reverseNumbers(nums,0,nums.size()-1);
        reverseNumbers(nums,0,k-1);
        reverseNumbers(nums,k,nums.size()-1);
    }
    
    void reverseNumbers(vector<int>& nums, int start, int end ){
        while(start<end){
            swap(nums,start,end);
            start++;
            end--;
        }
    }
    
};