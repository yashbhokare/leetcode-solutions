class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int maxResult = 0;
        int n= tokens.size();
        int left=0;
        int right=n-1;
        int score = 0;
        sort(tokens.begin(),tokens.end());
        while(left<=right){
            if(tokens[left]<=power){
                power=power-tokens[left];
                score++;
                left++;
            }else if(score>0){
                power=power+tokens[right];
                right--;
                score--;
            }else {
                break;
            }
            maxResult = max(maxResult,score);
        }
        return maxResult;
    }
};