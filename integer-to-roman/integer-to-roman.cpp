class Solution {
public:
    string intToRoman(int num) {
        vector<int> val = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> symbols = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string result = "";
        int index =0;
        while(num!=0){
            if(val[index]>num){
                index++;
                continue;
            }
            result+= symbols[index];
            num = num - val[index];
            
        }
        return result;
    }
};