class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size()-1;
        vector<int> leftMax(height.size());
        vector<int> rightMax(height.size());
        int result = 0;
        leftMax[0] = height[0];
        rightMax[n] = height[n];
        for(int i=1;i<=n;i++){
            leftMax[i] = max(leftMax[i-1],height[i]);
        }
        for(int i=n-1;i>=0;i--){
            rightMax[i] = max(rightMax[i+1],height[i]);
        }
        for(int i=0;i<=n;i++){
            result+= min(leftMax[i],rightMax[i])-height[i];
        }
        return result;
    }
};