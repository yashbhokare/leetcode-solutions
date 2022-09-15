class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> sortedHeights = heights;
        // sort(sortedHeights.begin(),sortedHeights.end());
        for(int i=0;i<sortedHeights.size();i++){
            for(int j=0;j<sortedHeights.size()-i-1;j++){
                if(sortedHeights[j]>sortedHeights[j+ 1])
                    swap(sortedHeights[j],sortedHeights[j+1]);
            }
        }
        
        int ans=0;
        for(int i=0;i<heights.size();i++){
            if(sortedHeights[i]!=heights[i]) ans++;
        }
        return ans;
    }
};