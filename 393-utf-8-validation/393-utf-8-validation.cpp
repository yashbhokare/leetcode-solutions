class Solution {
public:
    bool validUtf8(vector<int>& data) {
       

        int n =data.size();
        for(int i=0;i<n;i++){
            if(data[i]>=248) return false;
            
            string binary =  bitset<8>(data[i]).to_string(); //to binary
            // Check if the digit is 1 byte thne just continue
            if(binary[0]=='0') continue;
    
            // Check for number of bytes
            int bytes = numberOfBytes(binary);
            
            // If the bytes is 1 is not possible as the 1000000 is not valid according to UTF
            if(bytes==1) return false;
            
            // If the total bytes needed exceed the remaing values return false as no vallues to check
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