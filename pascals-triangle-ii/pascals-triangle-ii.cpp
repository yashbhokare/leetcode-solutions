class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // if(rowIndex=0) return {1};
        vector<int> result(rowIndex+1,1);
        for(int r=2;r<=rowIndex;r++){
            for(int c=r-1;c>=1;c--){
                result[c]=result[c]+result[c-1];
                // cout<<result[c]<<" ";
            }
            // cout<<endl;
        }
        return result;
        
    }
};