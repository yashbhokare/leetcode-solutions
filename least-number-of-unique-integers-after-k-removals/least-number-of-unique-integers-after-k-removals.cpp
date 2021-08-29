class Solution {
    struct compare{
        bool operator()(const pair<int, int>& a, const pair<int, int>& b)
        {
            return a.second < b.second;
        }
    } compare;
    public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> m;
        for(int val: arr){
            ++m[val];
        }
        vector<pair<int, int>> vec;

        for (auto it2=m.begin(); it2!=m.end(); it2++) 
        {
            vec.push_back(make_pair(it2->first, it2->second));
        }
        sort(vec.begin(), vec.end(), compare); 
        
        // for(auto it= m.begin();it!=m.end();it++){
        //     cout<<it->first<<"->"<<it->second<<"\n";
        // }
        auto it = vec.begin();
        int count = vec.size();
        while(it!=vec.end() && k!=0){
            it->second = it->second - 1;
            if(it->second == 0){
                count--;
                it++;
            }
            k--;
        }
        return count;  
    }
    

};