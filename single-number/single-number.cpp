class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // return hashTable(nums);
        return bitManipulation(nums);
    }
    
    int hashTable(vector<int> nums){
        unordered_set <int> numSet;
        for(int i=0; i< nums.size(); i++){
            if(numSet.find(nums[i]) == numSet.end()){
                numSet.insert(nums[i]);
            } else {
                numSet.erase(nums[i]);
            }
        }
        return *numSet.begin();
    }
    
    
// If we take XOR of zero and some bit, it will return that bit
//a ⊕ 0 =a
// If we take XOR of two same bits, it will return 0
// a⊕a = 0
// a⊕b⊕a=(a⊕a)⊕b=0⊕b=b
    int bitManipulation(vector<int> nums){
        int num = 0;
        for(int i=0; i< nums.size(); i++){
            num = num ^ nums[i];
        }
        return num;
    }
};