class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int> map;
        for(int i=0;i<arr.size();i++) map.insert({arr[i],i});
        
        for(int i=0;i<arr.size();i++){
            if(map.find(arr[i]*2)!=map.end() && map[arr[i]*2]!=i){
                return true;
            }
        }
        return false;
    }
};