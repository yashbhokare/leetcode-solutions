class Solution {
public:
    bool isRobotBounded(string instructions) {
        vector<vector<int>> directions = {
            {0,1}, // North at index 0
            {1,0}, // East at index 1
            {0,-1}, // South at index 2
            {-1,0} // West at index 3
        };
        
        int index = 0; //Start from north
        int x = 0, y=0; // Start positions
        
        for(int i=0;i<instructions.size();i++){
            if(instructions[i] == 'R'){
                index = (index + 1) % 4;
            } else if(instructions[i] == 'L'){
                index = (index + 3) % 4;
            } else {
                x = x + directions[index][0];
                y = y + directions[index][1];
            }

        }
        
        if(x == 0 && y == 0) return true;
        
        if(index != 0) return true;
        
        return false;
    }
};