class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> mapper;
        vector<int> numbers;
        for(auto ch:s) mapper[ch]++;
        
        for(auto it=mapper.begin();it!=mapper.end();it++){
            numbers.push_back(it->second);
        }
        
        sort(numbers.begin(),numbers.end());
        
        int result = 0;
        for(int i=numbers.size()-1;i>0;i--){
            if(numbers[i]==0){
                int diff = numbers[i-1]-numbers[i];
                numbers[i-1] = 0;
                result+=diff;
            }
            else if(numbers[i-1]>=numbers[i]){
                int diff = numbers[i-1]-numbers[i]+1;
                numbers[i-1] = numbers[i]-1;
                result+=diff;
            }
        }
        return result;
    }
};