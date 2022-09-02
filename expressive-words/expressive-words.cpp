class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        unordered_map<int,char> charMap;
        unordered_map<int,int>  countMap;
        int curIndex=0;
        int res = 0;
        for(int i=0;i<s.size();i++){
            if(i!=0 && s[i]!=s[i-1]){
                curIndex++;
            }
            charMap[curIndex] = s[i];
            countMap[curIndex]++;
        }
        
        for(int i=0;i<=curIndex;i++){
            cout<<i<<" "<<charMap[i]<<" "<<countMap[i]<<endl;
        }
        
        cout<<"******************\n";
        for(auto w:words){
            int index = 0;
            int count = 0;
            int i;
            // cout<<"\nWord:"<<w<<endl;
            for(i=0;i<=w.size();i++){
                 // cout<<s[i]<<endl;
                if(i==w.size() || (i!=0 && w[i]!=w[i-1])){
                    cout<<index<<"->"<<w[i-1]<<" "<<countMap[index]<<" "<<count<<endl;
                    if(charMap[index]==w[i-1] && (countMap[index]==count || (countMap[index]>=3 && count<countMap[index]))){
                        // cout<<w<<endl;
                    }else {
                        cout<<"Break"<<endl;
                        break;
                    }
                    index++;
                    count = 0;
                }
                count++;
            }
            if(i>w.size() && curIndex==index-1) res++;
        }
        
        return res;
    }
};