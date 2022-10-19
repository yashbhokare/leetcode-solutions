class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        vector<int> curr = {0};
        for(int i=0;i<n;i++){
            int power = pow(2,i); 
            // cout<<power<<" "<<curr[0]<<endl;
            for(int j=curr.size()-1;j>=0;j--){
                curr.push_back(curr[j]+power);
            }
        }
        return curr;
        
    }
};

//https://leetcode.com/problems/gray-code/solution/963962
// It's pretty simple with single iteration. We will start with [0]
// Even though bit 0 is not allowed but assume for bit 0 answer is [0]
// if bit ==0:
// [0]
// if bit==1: # Add 1 (2^0) to all the bit 0 elements and append it in reverse order, so that first and last elements different by only 1 bit
// [0]
// [1]
// if bit==2: # Add 2 (2^1) to all the bit 1 elements and append it in reverse order.
// [0]
// [1]
// [11]
// [10]
// if bit==3: # Add 4 (2^2) to all the bit 2 elements and append it in reverse order.
// [0]
// [1]
// [11]
// [10]
// [110]
// [111]
// [101]
// [100]
// if bit==n: Add(2^n-1) to all the bit n-1 elements and append it in reverse order.