class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
 
        int lastIndex = nums1.size()-1;
        int num1Point = m -1;
        int num2Point = n-1;
        while(num1Point >= 0 && num2Point>=0){
            if(nums1[num1Point] >  nums2[num2Point]){
                nums1[lastIndex] = nums1[num1Point];
                num1Point--;
            }else {
                nums1[lastIndex] =  nums2[num2Point];
                num2Point--;
            }
            lastIndex--;
        }
        while(num2Point>=0){
            nums1[num2Point] = nums2[num2Point];
            num2Point--;
        }
        // return nums1;
    }
    
        //    int i=m-1,j=n-1,k=m+n-1;
        // while(i>=0&&j>=0)
        // {
        //     if(nums1[i]>nums2[j])
        //     {
        //         nums1[k]=nums1[i];
        //         i--;
        //         k--;
        //     }
        //     else
        //     {
        //         nums1[k]=nums2[j];
        //         j--;
        //         k--;
        //     }
        // }
        // while(i>=0)
        //     nums1[k--]=nums1[i--];
        // while(j>=0)
        //     nums1[k--]=nums2[j--];
};