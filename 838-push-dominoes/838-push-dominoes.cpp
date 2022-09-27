class Solution {
public:
    string pushDominoes(string dominoes) {
        int n=dominoes.size();
        vector<int> left(n,0);
        vector<int> right(n,0);
        int count = 0;
        for(int i=0;i<n;i++){
            if(dominoes[i]=='R'){
                count=1;
            }else if(dominoes[i]=='.' && count!=0){
                count++;
            }else {
                count=0;
            }
            right[i]=count;
        }
        
        for(int i=n-1;i>=0;i--){
            if(dominoes[i]=='L'){
                count=1;
            }else if(dominoes[i]=='.' && count!=0){
                count++;
            }else {
                count=0;
            }
            left[i]=count;
        }
        
        for(int i=0;i<n;i++){
            char ch='.';
            if(left[i]==right[i]){
                ch='.';
            }else if(left[i]==0 || (right[i]!=0 && right[i]<left[i])){
                ch='R';
            }else if(right[i]==0 || (left[i]!=0 && left[i]<right[i])){
                ch='L';
            }
            dominoes[i]=ch;
        }
        return dominoes;
    }
};