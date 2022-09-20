class Solution {
public:
    // Using KMP algo
    // Creating longest of prefix which also contains suffix
    vector<int> lps(string needle){
        int n=needle.size();
        vector<int> l(n,0);
        int left=0;
        for(int right=1;right<n;right++){
            if(needle[right]==needle[left]){
                l[right] = left+1;
                left++;
                continue;
            }
            // int temp = right;
            while(left!=0){
                left = l[left-1];
                // temp=left;
                if(needle[left]==needle[right]){
                    l[right] = left+1;
                    left++;
                    break;
                }
            }
        }
        
        cout<<endl;
        return l;
    }
    
    
    int strStr(string haystack, string needle) {
        vector<int> l = lps(needle);
        int j=0;
        for(int i=0;i<haystack.size();i++){
            if(needle[j]==haystack[i]){
                j++;
            }else {
                while(j!=0){
                    j=l[j-1];
                    if(needle[j]==haystack[i]){
                        j++;
                        break;
                    }
                }
            }
            if(j==needle.size()) return i-j+1;
        }
        return -1;
    }
    
    
};