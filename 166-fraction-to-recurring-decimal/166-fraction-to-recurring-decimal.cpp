class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==denominator) return "1";
        if(numerator==0) return "0";
        long num = labs(numerator);
        long den = labs(denominator);
        string indicator = "-";
        string res="";
        if(numerator >0 ^ denominator>0){
            res= res + "-";
        }
        
        long dividend = num/den;
        long rem=num%den;
        res+=to_string(dividend);
        
        if(rem==0) return res;
        
        unordered_map<int,int> position;
        res=res+'.';
        while(rem>0){
            if(position.find(rem)!=position.end()){
                int index = position[rem];
                res.insert(index,"(");
                res+=")";
                break;
            }
            
            position[rem]=res.size();
            
            rem= rem*10;
            dividend = rem/den;
            
            res+=to_string(dividend);
            rem= rem%den;
        }
        
        return res;
    }
};