class Solution {
public:
    int secondHighest(string s) {
        int higest = -1;
        int second_higest = -1;
        for(auto ch:s){
            if(isdigit(ch)){
                int num = ch-'0';
                if(num>higest){
                    second_higest = higest;
                    higest = num;
                }else if(num>second_higest && num!=higest){
                    second_higest = num;
                }
            }
        }
        return second_higest;
    }
};