class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        return bfs(deadends,target);
    }
    
    int bfs(vector<string>& deadends, string target){
        string start="0000";
        queue<string> q;
        unordered_set<string> deadendset(deadends.begin(),deadends.end());
        unordered_set<string> visited;
        if(deadendset.find(start)!=deadendset.end()){
            return -1;
        }
        visited.insert(start);
        q.push(start);
        int steps=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                string curr=q.front();
                if(curr==target) return steps;
                q.pop();
                for(int j=0;j<4;j++){
                    string downTurn=curr;
                    string upTurn=curr;
                    downTurn[j]=downTurn[j]=='9'? '0' : downTurn[j]+1;
                    upTurn[j]=upTurn[j]=='0'? '9' : upTurn[j]-1;
                    
                    if(deadendset.find(downTurn)==deadendset.end() && 
                       visited.find(downTurn)==deadendset.end()){
                        q.push(downTurn);
                        visited.insert(downTurn);
                    }
                    if(deadendset.find(upTurn)==deadendset.end() && 
                       visited.find(upTurn)==deadendset.end()){
                        q.push(upTurn);
                        visited.insert(upTurn);
                    }
                }
            }
            steps++;
        }
        return -1;
        
    }
};