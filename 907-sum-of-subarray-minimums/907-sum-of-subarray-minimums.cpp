class Solution {
public:
    void display(vector<int> arr){
        for(auto a:arr) cout<<a<<" ";
        cout<<endl;
    }
    int sumSubarrayMins(vector<int>& arr) {
        
        // return sumSubarrayMinsO(arr);
        int n = arr.size();
        vector<int> leftMono(n,-1);
        vector<int> rightMono(n,-1);
        
        stack<int> lStack;
        for(int i=0;i<n;i++){
            while(!lStack.empty() && arr[lStack.top()]>arr[i]){
                lStack.pop();
            }
            int prev = lStack.empty() ? -1 : lStack.top();
            leftMono[i] = prev;
            lStack.push(i);
        }
        
        // display(leftMono);
        
        stack<int> rStack;
        for(int i=n-1;i>=0;i--){
            // * Important * Remember to make the sign >= as ther values are created for right monotone
            while(!rStack.empty() && arr[rStack.top()]>=arr[i]){
                rStack.pop();
            }
            int next = rStack.empty() ? -1 : rStack.top();
            rightMono[i] = next;
            rStack.push(i);
        }
        
        // display(rightMono);
        
        long ans = 0;
        long mod = 1e9 +7;
        for(int i=0;i<n;i++){
            int leftDistance = leftMono[i]==-1 ? i+1 : abs(leftMono[i]-i);
            int rightDistance = rightMono[i]==-1 ? n-i : abs(rightMono[i]-i);
            long multi = (leftDistance*rightDistance)%mod;
            long total = (arr[i]*multi)%mod;
            ans=(ans+total)%mod;
        }
        
       
        return ans%mod;
    }
    
};
// https://leetcode.com/problems/sum-of-subarray-minimums/discuss/178876/stack-solution-with-very-detailed-explanation-step-by-step