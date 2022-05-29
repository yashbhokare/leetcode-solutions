class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for(int i = n-1;i>=0;i--){
            if(digits[i] < 9 ){
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        digits.insert(digits.begin(),1);
        return digits;
    }
};

// Old soln
// class Solution {
// public:
//     vector<int> plusOne(vector<int>& digits) {
//         plusOneCalculations(digits,digits.size()-1);
//         return digits;
//     }
    
//     void plusOneCalculations(vector<int>& digits, int index) {
//         int cal = digits[index] + 1;
//         if(cal > 9 ) {
//             digits[index] = cal % 10;
//             if(index > 0){
//                 index--;
//                 plusOneCalculations(digits,index);
//             } else {
//                 digits.insert(digits.begin(),1);
//             } 
            
//         } else {
//             digits[index] = digits[index] + 1 ;
//         }
         
//     }


// };