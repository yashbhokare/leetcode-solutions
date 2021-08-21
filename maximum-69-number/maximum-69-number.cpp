class Solution {
public:
    int maximum69Number (int num) {
        string numVal = to_string(num);
        for(int i=0;i<numVal.length();i++){
            if(numVal[i]=='6'){
                numVal[i]='9';
                break;
            }
        }
        
        return stoi(numVal);
    }
};