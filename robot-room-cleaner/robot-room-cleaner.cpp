/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
public:
    unordered_set<string> visited;
    vector<vector<int>> dir = {
        {0,1},//North
        {1,0},//East
        {0,-1},//South
        {-1,0}//West
    };
    void returnBack(Robot& robot){
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }
    void backtrack(int r,int c,int d,Robot& robot ){
        string pair = to_string(r) + ","+to_string(c);
        visited.insert(pair);
        robot.clean();
        for(int i=0;i<4;i++){
            int newD = (d + i)%4;
            int newRow = r + dir[newD][0];
            int newCol = c + dir[newD][1];
            string pair = to_string(newRow) + ","+to_string(newCol);
            if(visited.find(pair) == visited.end() && robot.move()){
                backtrack(newRow,newCol,newD,robot);
                returnBack(robot);
            }
            robot.turnRight();
            
        }
    }
    
    void cleanRoom(Robot& robot) {

        backtrack(0,0,0,robot);
    }
};