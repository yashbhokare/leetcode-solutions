class Solution {
public:
    int largestVariance(string s) {
        int max_variance = 0;
        
        for(char i='a';i<='z';i++){
            for(char j='a';j<='z';j++){
                if(i==j) continue;
                int variance = getVariance(i,j,s);
                max_variance = max(max_variance,variance);
            }
        }
        return max_variance;
    }
    
    int getVariance(char a,char b,string s){
        bool has_b = false;
        bool first_b = false;
        int variance = 0;
        int max_variance = 0;
        for(auto ch:s){
            if(ch==b && variance==-1){
                continue;
            }
            if(ch==a){
                variance+=1;
            }else if(ch==b){
                has_b = true;
                
                if(variance>=0 && first_b){
                    first_b = false;
                }
                else if((variance-1)<0){
                    first_b = true;
                    variance = -1;
                }else {
                    variance-=1;
                }
                
            }
            // variance = max(0, variance)
            if(has_b){
                max_variance = max(variance,max_variance);
            }
        }
        return max_variance;
    }
};