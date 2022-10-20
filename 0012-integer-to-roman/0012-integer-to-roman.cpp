class Solution {
public:
    string intToRoman(int num) {
        vector<string> symbolMap = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        vector<int> numMap = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string result = "";
        int index=0;
        while(num>0){
            if(num<numMap[index]){
                index++;
                continue;
            }
            result+=symbolMap[index];
            num = num-numMap[index];
        }
        return result;
    }
};