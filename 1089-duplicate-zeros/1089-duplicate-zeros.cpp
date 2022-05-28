class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        
        int length = arr.size()-1;
        int dups = 0;
        for(int i=0;i<=length-dups;i++){
            if(arr[i]==0){
                if(i==length-dups){
                    arr[length]=0;
                    length--;
                    break;
                }
                dups++;
            }
        }
        
        int last = length-dups;
        for(int i=length;i>=0;i--){
            if(arr[last]!=0){
                arr[i]=arr[last];
                // last--;
            }else {
                arr[i]=arr[last];
                i--;
                arr[i]=0;
            }
            last--;
        }
        
    }
    
};