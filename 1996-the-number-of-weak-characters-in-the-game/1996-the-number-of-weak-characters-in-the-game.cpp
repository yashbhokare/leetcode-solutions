class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        // Sort in ascending order of attack, 
        // If attack is same sort in descending order of defense
        sort(properties.begin(), properties.end(), 
             [](const vector<int>& a, vector<int>& b) -> bool { 
                 return (a[0] == b[0] ? a[1] > b[1] : a[0] < b[0]);});
             
        int weakCharacters = 0;
        int maxDefense = 0;
        for (int i = (int)properties.size() - 1; i >= 0; i--) {
            // Compare the current defense with the maximum achieved so far
            if (properties[i][1] < maxDefense) {
                weakCharacters++;
            }
            maxDefense = max(maxDefense, properties[i][1]);
        }
        
        return weakCharacters;
    }
};