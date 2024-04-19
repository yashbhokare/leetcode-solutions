class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result="";
        int count=strs.size();
        int index=0;
        int max=strs[0].length();
        for(int i=0;i<max;i++){
            char similar=strs[0][i];
            for(int v=1;v<count;v++){
                if(strs[v].length()<=i) return result;
                if(strs[v][i]!=similar) return result;
                // cout<<similar<<endl;
            }
            result+=similar;
        }
        return result;
    }
};