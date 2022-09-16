class Solution {
public:
        int minFlips(string target) {
        int result =0;
        int state = '0';
        for(char val:target){
            if(val!=state){
                result++;
                state=val;
            }
        }
        return result;
    }
    

//     int minFlips(string target) {
//         int flips = 0;
//         string val = target;
//         for(int i=0;i<target.size();i++){
//             val[i] = '0';
//         }
//         for(int i=0;i<target.size();i++){
//             if(target == val)
//                 return flips;
//             if(target[i]!=val[i]){
//                 val = flip(i,val);
//                 flips++;
//             }
//         }
//         return flips;
//     }
    
//     string flip(int index,string target){
//         for(int i=index;i<target.size();i++){
//             if(target[i]=='0') target[i]='1';
//             else target[i] ='0';
//         }
//         return target;
//     }
};