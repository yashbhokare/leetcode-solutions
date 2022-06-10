class Solution {
public:
    int minSwaps(vector<int>& data) {
        int totalOnes = accumulate(data.begin(),data.end(),0);
        int maxWindow= totalOnes;
        int left=0,right=0;
        int maxOnesWindow = 0;
        int count=0;
        while(right<data.size()){
            count = count + data[right++];
            if(right-left>maxWindow){
                count = count - data[left++];
            }
            maxOnesWindow = max(maxOnesWindow,count);
        }
        
        
        return totalOnes-maxOnesWindow;
    }
};