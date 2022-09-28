class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int x = nums1.size();
        int y = nums2.size();
        if(x>y){
            return findMedianSortedArrays(nums2,nums1);
        }
        
        int low = 0;
        int high = x;
        while(low<=high){
            int posX = (low+high)/2;
            int posY = ((x+y+1)/2) - posX;
            
            int maxLeftX = posX==0 ? INT_MIN : nums1[posX-1];
            int minRightX = posX==x ? INT_MAX : nums1[posX];
            
            int maxLeftY = posY==0 ? INT_MIN : nums2[posY-1];
            int minRightY = posY==y ? INT_MAX : nums2[posY];
            
            if(maxLeftX<=minRightY && maxLeftY<=minRightX){
                int leftMax = max(maxLeftX,maxLeftY);
                int rightMin = min(minRightX,minRightY);
                cout<<leftMax;
                if((x+y)%2==0){
                    return (leftMax+rightMin)/2.0;
                }else {
                    return leftMax;
                }
            }else if(maxLeftX>minRightY){
                high = posX-1;
            }else {
                low = posX+1;
            }
        }
        return -1;
    }
};