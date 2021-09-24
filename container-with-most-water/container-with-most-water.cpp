class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxValue = 0;
        if(height.size()< 2) return 0;
        int start = 0;
        int end = height.size()-1;
        // for(int i=0;i<height.size();i++){
        //     for(int j=i+1;j<height.size();j++){
        //         int val = min(height[i],height[j]);
        //         maxValue= max(maxValue,val*(j-i));
        //     }
        // }
        while(start<end){
             
            if(height[start]<height[end]){
                maxValue= max(maxValue,height[start]*(end-start));
                start++;
            } else {
                maxValue= max(maxValue,height[end]*(end-start));
                end--;
            }
        }
        return maxValue;
    }
};