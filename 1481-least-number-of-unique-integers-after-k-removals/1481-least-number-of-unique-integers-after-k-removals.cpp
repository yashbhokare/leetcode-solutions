class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mapper;
        vector<int> countArray;
        int index=0;
        for(auto num:arr){
            if(mapper.find(num)!=mapper.end()){
                countArray[mapper[num]]++;
            }else {
                mapper[num] = index;
                index++;
                countArray.push_back(1);
            }
        }
        sort(countArray.begin(),countArray.end());
        
        int total = 0;
        for(int i=0;i<countArray.size();i++){
            k = k-countArray[i];
            if(k>=0) total++;
            else break;
        }
        
        return countArray.size()-total;
        
        
    }
};