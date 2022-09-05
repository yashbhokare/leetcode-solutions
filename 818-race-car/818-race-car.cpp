struct Car {
    long long position;
    long long speed;
    long long moves;
    Car(long long moves,long long position,long long speed) : position(position),moves(moves),speed(speed) {}
};

class Solution {
public:
    int racecar(int target) {
        queue<Car> que;
      
        que.push({0,0,1});
        set<pair<long long int, long long int>> visit;
        unordered_set<string> visited;
        while(!que.empty()){
            long long position = que.front().position;
            long long speed = que.front().speed;
            long long moves = que.front().moves;
            que.pop();
            
            if(target==position) return moves;
            // string combine = toString(position,speed);
            
            // if(visited.find(combine)!=visited.end()){
            //     continue;
            // }
            if(visit.find({position,speed})!=visit.end()) continue;
            visit.insert({position,speed});
            // visited.insert(combine);
            
            que.push({moves+1,position+speed,speed*2});
            
            if((position+speed>target && speed>0) || (position+speed<target && speed < 0)){
                speed = speed > 0 ? -1 : 1;
                
                que.push({moves+1,position,speed});
            }
            
        }
        return target;
    }
    
    string toString(long long a,long long b){
        return to_string(a)+','+to_string(b);
        
    }
};