class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mapper;
        int count = 0;
        int pos =0;
        int result = INT_MIN;
        for(int i=0;i<fruits.size();i++){
            
            if(mapper.find(fruits[i]) == mapper.end()){
                count++;
                mapper.insert({fruits[i],1});
            }else {
                mapper[fruits[i]]++;
            }
            
            while(count>2){
                mapper[fruits[pos]]--;
                if(mapper[fruits[pos]]==0){
                    count--;
                    mapper.erase(fruits[pos]);
                }
                pos++;
            }
            result = max(result,i-pos+1);
        }
        return result;
    }
};