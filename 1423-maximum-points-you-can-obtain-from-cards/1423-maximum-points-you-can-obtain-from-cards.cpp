class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int window_size = n-k;
        int total_sum = 0;
        int window_sum =0;
        int min_window_sum=0;
        for(int i=0;i<window_size;i++){
            window_sum+=cardPoints[i];
            total_sum+=cardPoints[i];
        }
        min_window_sum = window_sum;
        int left = 0;
        for(int right=window_size;right<n;right++){
            window_sum=window_sum-cardPoints[left]+cardPoints[right];
            min_window_sum = min(min_window_sum,window_sum);
            total_sum+=cardPoints[right];
            left++;
        }
        cout<<min_window_sum;
        return total_sum-min_window_sum;
        
    }
};