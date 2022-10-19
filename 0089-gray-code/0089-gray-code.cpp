class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        vector<int> curr = {0};
        for(int i=0;i<n;i++){
            int power = pow(2,i); 
            // cout<<power<<" "<<curr[0]<<endl;
            for(int j=curr.size()-1;j>=0;j--){
                curr.push_back(curr[j]+power);
            }
        }
        return curr;
        
    }
};