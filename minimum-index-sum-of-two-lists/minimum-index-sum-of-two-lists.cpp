class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
         unordered_map<string,int> mapper;
        for(int i=0;i<list1.size();i++){
            mapper[list1[i]]=-(i+1);
            // cout<<list1[i]<<" "<<mapper[list1[i]]<<endl;
        }
        int minValue=INT_MAX;
        for(int i=0;i<list2.size();i++){
            if(mapper.find(list2[i])!=mapper.end()){
                int sum=(-mapper[list2[i]])+i+1;
                mapper[list2[i]]=sum;
                minValue=min(minValue,sum);
            }
        }
        
        vector<string> result;
        for(auto it=mapper.begin();it!=mapper.end();it++){
            if(it->second>0 && it->second==minValue) result.push_back(it->first);
        }
        return result;
        
    }
};