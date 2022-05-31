// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         unordered_set<int> seen;
//         for (auto &num : nums) {
//             if (seen.count(num))
//                 return num;
//             seen.insert(num);
//         }
//         return -1;
//     }
    
//     int findDuplicateUsingArrayAsHashMap(vector<int>& nums) {
//         while (nums[0] != nums[nums[0]])
//             swap(nums[0], nums[nums[0]]);
//         return nums[0];
//     }
    
// };

// Similar to https://leetcode.com/problems/linked-list-cycle-ii/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        // Find the intersection point of the two runners.
        int tortoise = nums[0];
        int hare = nums[0];

        do {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        } while (tortoise != hare);

        // Find the "entrance" to the cycle.
        tortoise = nums[0];
        while (tortoise != hare) {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }

        return hare;
    }
};