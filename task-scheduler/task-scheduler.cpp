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
            if(freq == f_max){
                idleTime = idleTime - (freq - 1);
// The idea is that if we have two tasks with the same max frequency (for instance A=3 and B=3) 
// then when we try to place B we do not consume 3 idle slots, but 2 (f_max-1), because B overflows the last location of A:
// ["A", "B", " ", "A", "B", " ", "A", "B"].
            }else {
                idleTime = idleTime - freq;
            }
            
        }
        idleTime = max(0,idleTime);
        return tasks.size() + idleTime;
    }
};