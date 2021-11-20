class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int start = 0;
        int end= tokens.size()-1;
        int ans = 0;
        int score = 0;
        while(start<=end && (power>=tokens[start] || score > 0)){
            while(start<=end && power>=tokens[start]){
                power = power - tokens[start];
                score++;
                start++;
            }
            ans = max(ans,score);
             if(start<=end && score > 0){
                 power = power + tokens[end];
                 score--;
                 end--;
             }
            cout<<power<<endl;
        }
        return ans;
    }
};