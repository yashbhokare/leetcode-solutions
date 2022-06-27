class Solution {
public:
    int maxScore(vector<int> &cardPoints, int k) {
        int n = cardPoints.size();

        int frontSetOfCards[k + 1];
        int rearSetOfCards[k + 1];

        //Intialize 0th index in both the arrays
        frontSetOfCards[0] = rearSetOfCards[0] = 0;

        for (int i = 0; i < k; i++) {
            frontSetOfCards[i + 1] = cardPoints[i] + frontSetOfCards[i];
            rearSetOfCards[i + 1] = cardPoints[n - i - 1] + rearSetOfCards[i];
        }

        int maxScore = 0;
        // Each i represents the number of cards we take from the front.
        for (int i = 0; i <= k; i++) {
            int currentScore = frontSetOfCards[i] + rearSetOfCards[k - i];
            maxScore = max(maxScore, currentScore);
        }

        return maxScore;
    }
};
