class Solution {
public:
    string nextClosestTime(string time) {
        vector<int> nums;
        for(auto ch:time){
            if(ch!=':') nums.push_back(ch-'0');
        }
        sort(nums.begin(),nums.end());
        int n = time.size();
        
        for(int i=4;i>=0;i--){
            if(i==2) continue;
            auto higher = upper_bound(nums.begin(),nums.end(),time[i]-'0');
            if(higher!=nums.end()){
                time[i] = '0'+*higher;; 
                if(i>2){
                    string newTime = time.substr(3,2);
                    if(stoi(newTime)<60) return time;
                }else {
                    string newTime = time.substr(0,2);
                    if(stoi(newTime)<24) return time;
                }
            }
            time[i] = nums[0]+'0';
            
        }
        return time;


    }
};