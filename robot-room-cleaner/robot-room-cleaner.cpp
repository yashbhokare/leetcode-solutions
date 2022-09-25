// /**
//  * // This is the robot's control interface.
//  * // You should not implement it, or speculate about its implementation
//  * class Robot {
//  *   public:
//  *     // Returns true if the cell in front is open and robot moves into the cell.
//  *     // Returns false if the cell in front is blocked and robot stays in the current cell.
//  *     bool move();
//  *
//  *     // Robot will stay in the same cell after calling turnLeft/turnRight.
//  *     // Each turn will be 90 degrees.
//  *     void turnLeft();
//  *     void turnRight();
//  *
//  *     // Clean the current cell.
//  *     void clean();
//  * };
//  */

// class Solution {
// public:
//     vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
//     set<pair<int,int>> cleanedSet;

//     void cleanRoom(Robot& robot) {
//          int x=0,y=0;
//          rec(robot,x,y);
//     }
    
    
//     void rec(Robot& robot,int x,int y){
//         if(cleanedSet.find({x,y})!=cleanedSet.end()) return;
        
//         robot.clean();
//         cleanedSet.insert({x,y});
       
//         moveUp(robot,x,y);
//         moveLeft(robot,x,y);
//         moveDown(robot,x,y);
//         moveRight(robot,x,y);
//     }
    
    
//     void moveUp(Robot& robot,int x,int y){
//         int newX = x-1;
//         int newY = y;
//         if(cleanedSet.find({newX,newY})!=cleanedSet.end()) return;
//          bool res = robot.move();
//         if(res){
//             rec(robot,newX,newY);
//             robot.turnRight();
//             robot.turnRight();
//             robot.move();
//             robot.turnRight();
//             robot.turnRight();
//         }else {
//              cleanedSet.insert({newX,newY});
//         }
//     }
    
//     void moveDown(Robot& robot,int x,int y){
//         int newX = x+1;
//         int newY = y;
//         if(cleanedSet.find({newX,newY})!=cleanedSet.end()) return;
//         robot.turnRight();
//         robot.turnRight();
//         bool res = robot.move();
//         robot.turnLeft();
//         robot.turnLeft();
//         if(res){
//            rec(robot,newX,newY);
//            robot.move();
//         }else {
//              cleanedSet.insert({newX,newY});
//         }
//     }
    
//     void moveLeft(Robot& robot,int x,int y){
//         int newX = x;
//         int newY = y-1;
//         if(cleanedSet.find({newX,newY})!=cleanedSet.end()) return;
//         robot.turnLeft();
//         bool res = robot.move();
//         robot.turnRight();
//         if(res){
//             rec(robot,newX,newY);
//             robot.turnRight();
//             robot.move();
//             robot.turnLeft();
//         }else {
//              cleanedSet.insert({newX,newY});
//         }
//     }
    
//     void moveRight(Robot& robot,int x,int y){
//         int newX = x;
//         int newY = y+1;
        
//         if(cleanedSet.find({newX,newY})!=cleanedSet.end()) return;
//         robot.turnRight();
//         bool res = robot.move();
//         robot.turnLeft();
//         if(res){
//             rec(robot,newX,newY);
//             robot.turnLeft();
//             robot.move();
//             robot.turnRight();
//         }else {
//              cleanedSet.insert({newX,newY});
//         }
//     }
// };

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