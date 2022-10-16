class Solution {
public:
    string nextClosestTime(string time) {
        vector<int> t;
        for(auto ch:time) {
            if(ch==':') continue;
            t.push_back(ch-'0');
        }
        sort(t.begin(),t.end());
        for(int i=time.size()-1;i>=0;i--){
            if(i==2) continue;
            int curr = time[i]-'0';
            auto high = upper_bound(t.begin(),t.end(),curr);
            if(high!=t.end()){
                 time[i] = *high+'0';
                if(i>2){
                    if(stoi(time.substr(3,2))<60){
                        return time;
                    }
                }else{
                    if(stoi(time.substr(0,2))<24){
                        return time;
                    }
                }
            }
            time[i] = t[0]+'0';
        }
        return time;

    }
};