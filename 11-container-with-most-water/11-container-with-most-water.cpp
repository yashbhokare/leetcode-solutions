class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int result = 0;
        while(left<right){
            int total = 0;
            if(height[left] <= height[right]){
                total = height[left]*(right-left);
                left++;
            }else {
                total = height[right]*(right-left);
                right--;
            }
            result = max(total,result);
        }
        return result;
    }
};