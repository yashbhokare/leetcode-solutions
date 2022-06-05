class Solution {
public:
    int compress(vector<char>& chars) {
        chars.push_back(' ');
        if(chars.size() == 1) return 1;
        vector<char> res;
        int count=1;
        char prev=chars[0];
        int index=0;
        for(int i=1;i<chars.size();i++){
            if(i<chars.size()-1 && chars[i]==prev){
                count++;
            }else {
                cout<<prev<<" "<<count<<endl;
                chars[index++]=prev;
                string number="";
                if(count>1){
                    number=to_string(count);
                    // cout<<number.size();
                    for(int j=0;j<number.size();j++){
                        chars[index++]=number[j];
                    }
                }
                // cout<<i<<endl;
                prev=chars[i];
                count=1;
            }
        }
        return index;
    }
};