// class Solution {
// public:
//     int oddEvenJumps(vector<int>& arr) {
//         vector<int> oddJumps(arr.size(),-1);
//         vector<int> evenJumps(arr.size(),-1);
        
//         oddJumps = getOddJumps(arr);
//         evenJumps = getEvenJumps(arr);
//         // display(oddJumps,evenJumps);
//         return calResult(oddJumps,evenJumps);
//         // return 0;
//     }
    
//     vector<int> getOddJumps(vector<int>& arr){
//         vector<int> res(arr.size(),-1);
//         for(int i=0;i<arr.size();i++){
//             if(i==arr.size()-1){
//                 res[i] = i;
//             }else {
//                 res[i] = minValueIndex(arr,i+1,arr[i]);
//             } 
//         }
//         return res;
//     }
    
//     vector<int> getEvenJumps(vector<int>& arr){
//         vector<int> res(arr.size(),-1);
//         for(int i=0;i<arr.size();i++){
//             if(i==0){
//                 res[i] = -1;
//             }else {
//                 res[i] = maxValueIndex(arr,i+1,arr[i]);
//             } 
//         }
//         return res;
//     }
    
//     int minValueIndex(vector<int>& arr,int start, int val){
//         int minVal = INT_MAX;
//         int index = -1;
//         for(int i=start;i<arr.size();i++){
//             if(arr[i]>=val && arr[i]<minVal){
//                 minVal = arr[i];
//                 index = i;
//             }
//         }
//         return index;
//     }
    
//     int maxValueIndex(vector<int>& arr,int start, int val){
//         int maxVal = INT_MIN;
//         int index = -1;
//         for(int i=start;i<arr.size();i++){
//             if(arr[i]<=val && arr[i]>maxVal){
//                 maxVal = arr[i];
//                 index = i;
//             }
//         }
//         return index;
//     }
    
//     int calResult(vector<int> oddJumps,vector<int> evenJumps){
//         int result = 0;
//         int lastIndex = oddJumps.size()-1;
//         bool oddJump = true;
//         for(int index=0;index<oddJumps.size();index++){
//             int newIndex = index;
//             while(newIndex!=-1){
//                 if(oddJump){
//                     newIndex = oddJumps[newIndex];
//                 }else {
//                     newIndex = evenJumps[newIndex];
//                 }
//                 if(newIndex==lastIndex){
//                     result++;
//                     break;
//                 } 
//                 oddJump = !oddJump;
//             }
//             oddJump = true;
//         }
//         return result;
//     }
    
//     void display(vector<int> oddJumps,vector<int> evenJumps){
//          for(int index=0;index<oddJumps.size();index++){
//              cout<<oddJumps[index]<<" ";
//          }
//         cout<<endl;
//         for(int index=0;index<oddJumps.size();index++){
//              cout<<evenJumps[index]<<" ";
//          }
//     }
// };

class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
     
        int n=arr.size();
        vector<int>odd(n,0);
        vector<int>even(n,0);
        map<int,int>m;
        odd[n-1]=1;
        even[n-1]=1;
        m[arr[n-1]]=n-1;
        int ans=1;
        for(int i=n-2;i>=0;i--){
            auto it = m.lower_bound(arr[i]);//odd jump--->taking the odd numbered jump from this pos
            auto it2= m.upper_bound(arr[i]);//even jump--->taking the even numbered jump from this pos 
            
            int idx;
            if(it!=m.end()){
                //since this jump was odd next jump would be even
                idx= it->second;
                if(even[idx])odd[i]=1;
            }
            if(it2!=m.begin() ){
                //since this jump was even next jump would be odd
                it2--;
                //it2 was the upperbound and one number before it would be less or equal to the current number
                idx= it2->second;
                if(odd[idx])even[i]=1;
            }
            m[arr[i]]=i;
            if(odd[i]){
                cout<<i<<" ";
            //since the starting position will always be odd therfore incrementing only at odd position
                ans++;
            }
        }
        return ans;
        
    }
};