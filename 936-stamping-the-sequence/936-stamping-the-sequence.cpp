class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> result;
        
        int sLen = stamp.length();
        int tLen = target.length()-sLen+1;
        int i=0,j=0;
        
        bool targetDiff = true;
        bool sDiff = false;
        while(targetDiff){
            
            for(i=0,targetDiff=false;i<tLen;i++){
                for(j=0,sDiff=false;j<sLen;j++){
                    if(target[i+j]=='*') continue;
                    else if(target[i+j]!=stamp[j]) break;
                    sDiff = true;
                }
                
                if(j==sLen && sDiff){
                    targetDiff= true;
                    for(int k=i;k<i+sLen;k++){
                        target[k]='*';
                    }
                    result.push_back(i);
                }
            }
        }
        
        // cout<<result.size();
        for(auto t:target){ 
            // cout<<t;
            if(t!='*'){
                return {};
            }
        }
            
        reverse(result.begin(),result.end());
        return result;
        
        
    }
};