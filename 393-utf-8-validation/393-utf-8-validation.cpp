class Solution {
public:
    bool validUtf8(vector<int>& data) {
       

        int n =data.size();
        for(int i=0;i<n;i++){
            if(data[i]>=248) return false;
            
            string binary =  bitset<8>(data[i]).to_string(); //to binary
            if(binary[0]=='0') continue;
            
            int bytes = numberOfBytes(binary);
            if(bytes==1) return false;
            if(i+bytes>n) return false;
            
            if(!isValidOctetSequence(data,i,bytes)){
                return false;
            }
            i = i+bytes-1;

        }
        return true;
    }
    
    int numberOfBytes(string s){
        int count = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1') count++;
            else return count;
        }
        return count;
    }
    
    bool isValidOctetSequence(vector<int>& data,int start,int max){
        for(int i=start+1;i<start+max;i++){
            string binary =  bitset<8>(data[i]).to_string(); //to binary
            if(numberOfBytes(binary)!=1) return false;
        }
        return true;
    }
};