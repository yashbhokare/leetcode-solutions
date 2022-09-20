class Solution {
public:
    vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        
    string numberToWords(int num) {
        if(num==0) return "Zero";
        return numberToWord(num).substr(1);

        
    }
        string numberToWord(int num){
            if(num>=1000000000){
                return numberToWord(num/1000000000)+" Billion" + numberToWord(num%1000000000);
            }
            if(num>=1000000){
                return numberToWord(num/1000000)+" Million" + numberToWord(num%1000000);
            }
            if(num>=1000){
                return numberToWord(num/1000)+" Thousand" + numberToWord(num%1000);
            }
            if(num>=100){
                return numberToWord(num/100)+" Hundred"+numberToWord(num%100);
            }
            if(num>=20){ 
                    return " "+tens[num/10]+numberToWord(num%10);
            }
            if(num>=1){
                return " " + ones[num];
            }
            return "";

        }
};