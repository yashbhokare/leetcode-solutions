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
            char ch = time[i];
            auto higher = upper_bound(nums.begin(),nums.end(),time[i]-'0');
            if(higher!=nums.end()){
                char newV  = '0'+*higher;
                time[i] = newV; 
            
                if(i>2){
                    string newTime = to_string(time[3]-'0')+to_string(time[4]-'0');
                    if(stoi(newTime)<60) return time;
                    else time[i] = nums[0]+'0';
                }else {
                    string newTime = to_string(time[0]-'0')+to_string(time[1]-'0');
                    if(stoi(newTime)<24) return time;
                    else time[i] = nums[0]+'0';
                }
                // cout<<time<<endl;
            }
            else time[i] = nums[0]+'0';
            
        }
        return time;


    }
};