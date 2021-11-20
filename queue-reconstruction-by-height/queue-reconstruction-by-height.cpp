class Solution {

public:
    static bool comparator(vector<int>& a,vector<int>& b){
        if(a[0] == b[0]) return a[1] < b[1];
        else return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),comparator);
        vector<vector<int>> result;
        for(int i=0;i<people.size();i++){
            int index = people[i][1];
            result.insert(result.begin()+index,people[i]);
        }
        return result;
    }
};