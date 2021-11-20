class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        if(limit==1) return people.size();
        int ans=0;
        sort(people.begin(),people.end());
        int startPos = 0;
        int lastPos = people.size()-1;
        while(startPos<=lastPos){
            if(people[startPos] + people[lastPos]<=limit){
                startPos++;
                lastPos--;
            }else {
                lastPos--;
            }
            ans++;
        }
        return ans;
    }
};