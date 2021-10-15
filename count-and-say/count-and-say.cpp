class Solution {
public:
    string countAndSay(int n) {
        return countAndSayCal(n);
    }
    
    string countAndSayCal(int n){
        if(n==1){
            return "1";
        }else {
            string num = countAndSayCal(n-1);
            int count = 1,pos =0;
            
            
            string result = "";
            for(int i =0;i<num.length()-1;i++){
                if(num[i]!=num[i+1]){
                    result = result + to_string(count)+ num[i];
                    count=0;
                }
                count++;
            }
            result = result + to_string(count) + num[num.length()-1];
            return result;
            // string newNum = "";
            // for(int i =0;i<num.length();i++){
            //     if(num[pos]==num[i]){
            //         count++;
            //     }else{
            //         newNum = newNum + to_string(count) +num[pos];
            //         count = 1;
            //         pos = i;
            //     }
            // }
            // newNum = newNum + to_string(count) +num[pos];
            // return newNum;
        }
    }
};