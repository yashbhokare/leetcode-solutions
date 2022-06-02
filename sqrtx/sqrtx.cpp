class Solution {
public:
    int mySqrt(int x) {
        if (x <2 )
            return x;
        int mid, answer;
        
        int low = 0, high = x;
        while (low <= high){
            mid = (low + high) / 2;
            if (mid <= x / mid){
                answer = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return answer;
    }
};