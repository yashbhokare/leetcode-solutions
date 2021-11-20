class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n==0) return tasks.size();
        vector<int> alpha(26,0);
        for(char c:tasks){
            alpha[c-'A']++;
        }
        sort(alpha.begin(),alpha.end(),greater<int>());
        int f_max = alpha[0];
        int idleTime = (f_max-1)*n;
        for(int i=1;i<26;i++){
            int freq = alpha[i];
            idleTime = idleTime - min(f_max-1,freq);
        }
        idleTime = max(0,idleTime);
        return tasks.size() + idleTime;
    }
};