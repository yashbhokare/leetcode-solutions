struct Car {
    long long position;
    long long speed;
    long long moves;
    Car(long long moves,long long position,long long speed) : position(position),moves(moves),speed(speed) {}
};

class Solution {
public:
    int racecar(int target) {
        queue<Car*> que;
        Car* newNode = new Car(0,0,1);
        que.push(newNode);
        unordered_set<string> visited;
        while(!que.empty()){
            long long position = que.front()->position;
            long long speed = que.front()->speed;
            long long moves = que.front()->moves;
            que.pop();
            
            if(target==position) return moves;
            string combine = toString(position,speed);
            
            if(visited.find(combine)!=visited.end()){
                continue;
            }
            
            visited.insert(combine);
            
            que.push(new Car(moves+1,position+speed,speed*2));
            
            if((position+speed>target && speed>0) || (position+speed<target && speed < 0)){
                speed = speed > 0 ? -1 : 1;
                
                que.push(new Car(moves+1,position,speed));
            }
            
        }
        return target;
    }
    
    string toString(long long a,long long b){
        return to_string(a)+','+to_string(b);
        
    }
};