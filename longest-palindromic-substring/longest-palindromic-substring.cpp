class Solution {
public:
    string longestPalindrome(string s) {
        
        if(s.length()<=1) return s;
        int start =0,finalLength = 1;
        int n = s.length()-1;
        vector<vector<int>> tableMatrix(s.length(),vector<int>(s.length(),0));
        
        for(int i=0;i<n;i++){
            if(s[i]==s[i+1]){
                tableMatrix[i][i+1] = 1;
                finalLength = 2;
                start =i;
            }
            tableMatrix[i][i] = 1;
        }
        tableMatrix[n][n] = 1;
        
        
        for(int k=2;k<=n;k++){
            for(int i=0;i<=n-k;i++){
                int j = i+k;
                if(s[i]==s[j] && tableMatrix[i+1][j-1]){
                    tableMatrix[i][j] = 1;
                    int tempLen = j-i+1;
                    if(tempLen > finalLength ){
                        finalLength = tempLen;
                        start =i; 
                    }
                }
            }
        }
        // displayMatrix(tableMatrix,s.length());
        return s.substr(start,finalLength);
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
//         if(s.length()<=1){
//             return s;
//         }
//         string result;
//         string finalResult = string(1,s[0]);
//         for(int i=0;i<s.length();i++){
//             result = string(1,s[i]);
//             for(int j=s.length()-1;j>i;j--){
//                 if(s[i]==s[j]){
//                     result = s.substr(i,j-i+1);
//                     if(isPalindrome(result) && result.length() > finalResult.length()){
//                         finalResult = result;
//                     }
//                     if(finalResult.length() == s.length()){
//                         return finalResult;
//                     }
//                 }
//             }
//         }
        
//         return finalResult;
    }
    
 // bool isPalindrome(string s){
 //     //  cout<<"Inside Value:"<<s<<endl;
 //     // for(int i=0,j=s.length()-1;i<s.length()/2;i++,j--){
 //     //    if(s[i]!=s[j]){
 //     //        return false;
 //     //    }     
 //     // }
 //     string reverseString = s;
 //     reverse(reverseString.begin(),reverseString.end());
 //     if(s == reverseString)  return true;
 //     return false;   
 // }
    
    void displayMatrix(vector<vector<int>> tableMatrix , int n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<tableMatrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};