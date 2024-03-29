// class Solution {
// public:
//     vector<int> findOriginalArray(vector<int>& changed) {
//         if(changed.size()%2!=0) return {};
        
//         int reqSize = changed.size()/2;
        
//         unordered_map<int,int> mapper;
//         for(auto num:changed) mapper[num]++;
        
//         sort(changed.begin(),changed.end());
//         vector<int> resultArray;
//         for(auto num:changed)
//         {
//             if(num==0 && mapper[num]<2) continue;
            
//             if(mapper[num] && mapper[num*2]){
//                 mapper[num]--;
//                 mapper[num*2]--;
//                 resultArray.push_back(num);
//             }
//             if(resultArray.size()>reqSize) return {};
//         }
//         if(resultArray.size()==reqSize){
//             return resultArray;
//         }else {
//             return {};
//         }
//     }
// };

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        // It can't be doubled array, if the size is odd
        if (changed.size() % 2) {
            return {};
        }
        
        int maxNum = 0;
        // Find the max element in the array
        for (int num : changed) {
            maxNum = max(maxNum, num);
        }
        
        vector<int> freq(2 * maxNum + 1, 0);
        // Store the frequency in the map
        for (int num : changed) {
            freq[num]++;
        }
        
        vector<int> original;
        for (int num = 0; num <= maxNum; num++) {
            // If element exists
            if (freq[num]) {
                freq[num]--;
                
                int twiceNum = num * 2;
                if (freq[twiceNum] > 0) {
                    // Pair up the elements, decrement the count
                    freq[twiceNum]--;
                    // Add the original number to answer
                    original.push_back(num);
                    num--;
                } else {
                    return {};
                }
            }
        }
        
        return original;
    }
};