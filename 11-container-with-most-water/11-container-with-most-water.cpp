class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxVal = 0;
        int n = height.size();
        int left = 0;
        int right = n-1;
        while(left<right){
            int total;
            if(height[left]<height[right]){
                total = height[left]*(right-left);
                left++;
            }else {
                total = height[right]*(right-left);
                right--;
            }
            maxVal = max(maxVal,total);
        }
        return maxVal;
    }
};