class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int res=0;
        int div=1;
        int constant = 0;
        while(constant<n){
            if((n-constant)%div==0){
                cout<<n<<" "<<constant<<"  "<<div<<endl;
                res++;
            }
            constant= constant + div;
            div++;
        }
        return res;
    }
};