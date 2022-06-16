// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left=1;
        int right=n;
        while(left<right){
            int mid=left+(right-left)/2;
            cout<<mid<<endl;
            bool res = isBadVersion(mid);
            if(!res){
                left=mid+1;
            }else {
                right=mid;
            }
        }
        return right;
    }
};