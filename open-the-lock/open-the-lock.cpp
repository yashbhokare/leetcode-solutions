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
                    string newString=curr;
                    newString[j]=newString[j]=='9'? '0' : newString[j]+1;
                    if(deadendset.find(newString)==deadendset.end() && visited.find(newString)==deadendset.end()){
                         // cout<<newString<<endl;
                        q.push(newString);
                        visited.insert(newString);
                    }
                }
                for(int j=0;j<4;j++){
                    string newString=curr;
                    newString[j]=newString[j]=='0'? '9' : newString[j]-1;
                   
                    if(deadendset.find(newString)==deadendset.end() && visited.find(newString)==deadendset.end()){
                        // cout<<newString<<endl;
                        q.push(newString);
                        visited.insert(newString);
                    }
                }
            }
            steps++;
        }
        return -1;
        
    }
};