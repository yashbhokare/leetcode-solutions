class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int result = 0;
        int n = seats.size();
        
        if(n==0) return result;
        
        vector<int> left(n,n-1);
        vector<int> right(n,n-1);
        
        if(seats[0]==1) left[0]=0;
        for(int i=1;i<n;i++){
            if(seats[i]==1)left[i]=0;
            else left[i] = left[i-1]+1;
        }
        
        if(seats[n-1]==1) right[n-1]=0;
        for(int i=n-2;i>=0;i--){
            if(seats[i]==1) right[i]=0;
            else right[i] = right[i+1]+1;
        }
        
        for(int i=0;i<n;i++){
            // cout<<left[i]<<" "<<right[i]<<endl;
            int minVal = min(left[i],right[i]);
            // if(minVal==INT_MAX) continue;
            result = max(minVal,result);
        }
        return result;
    }
};