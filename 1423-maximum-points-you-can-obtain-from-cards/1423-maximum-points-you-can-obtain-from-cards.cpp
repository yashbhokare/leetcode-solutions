class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int minWindowSize = cardPoints.size()-k;
        int total = accumulate(cardPoints.begin(),cardPoints.begin()+minWindowSize,0);
        int left=0;
        int minTotal = total;
        for(int right=minWindowSize;right<cardPoints.size();right++){
            total=total+cardPoints[right]-cardPoints[left++];
            minTotal = min(total,minTotal);
        }
        
        int totalSum = accumulate(cardPoints.begin(),cardPoints.end(),0);
        
        return totalSum-minTotal;
        
        
    }
};