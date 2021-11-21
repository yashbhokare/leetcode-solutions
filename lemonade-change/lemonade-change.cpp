class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        // sort(bills.begin(),bills.end());
        unordered_map<int,int> mapper;
        for(int i=0;i<bills.size();i++){
            if(bills[i] == 5) 
            {
                mapper[5]++;
            }
            if(bills[i] == 10){
                mapper[5]--;
                mapper[10]++;
            }
            if(bills[i]==20){
                if(mapper[10]) mapper[10]--;
                else mapper[5]-=2;
                mapper[5]--;
            }
            cout<<bills[i]<<endl;
            if(mapper[5] < 0 || mapper[10] < 0 ) return false;
        }
        return true;
        
    }
};