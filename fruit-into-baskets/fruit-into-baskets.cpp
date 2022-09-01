class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> map;
        int left=0;
        int maxVal = 1;
        for(int right=0;right<fruits.size();right++){
            int curFruit = fruits[right];
            map[curFruit]++;
            
            if(map.size()>2){
                int oldFruit = fruits[left];
                map[oldFruit]--;
                if(map[oldFruit]==0) map.erase(oldFruit);
                // maxVal= max(maxVal,right-left+1);
                // cout<<left<<" "<<right<<endl;
                left++;
            }
            maxVal= max(maxVal,right-left+1);
            
        }
        return maxVal;
    }
};