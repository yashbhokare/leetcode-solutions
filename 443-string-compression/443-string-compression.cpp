class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size() == 1) return 1;
        vector<char> res;
        int count=1;
        char prev=chars[0];
        int index=0;
        for(int i=1;i<=chars.size();i++){
            if(i<chars.size() && chars[i]==prev){
                count++;
            }else {
                chars[index++]=prev;
                cout<<chars[index];
                string number="";
                if(count>1){
                    number=to_string(count);
                    for(int j=0;j<number.size();j++){
                        chars[index++]=number[j];
                    }
                }
                if(i<chars.size())  prev=chars[i];
                count=1;
            }
        }
        return index;
    }
};