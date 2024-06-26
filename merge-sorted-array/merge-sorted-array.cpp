class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index1=m-1;
        int index2=n-1;
        for(int i=nums1.size()-1;i>=0;i--){
            int val1 = index1>=0 ? nums1[index1] : INT_MIN;
            int val2 = index2>=0 ? nums2[index2] : INT_MIN;
            if(val1>val2){
                nums1[i]=val1;
                index1--;
            }else {
                nums1[i]=val2;
                index2--;
            }
        }
    }
};