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


/*
* Direction
* 0 - up, 1 - right, 2 - down, 3 - left
*/
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

class Solution {
public:
    set<pair<int,int>> vis;
    
    // robot has to physically go back to the earlier cell
    // this is the diff between software implementation of DFS and hardware implementation
    void GoBack(Robot& robot) {
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }
    
    void Dfs(int x, int y, int d, Robot& robot) {
        vis.insert({x, y});
        robot.clean();
        
        for (int i=0; i<4; i++) {
            int nd = (d + i) % 4;
            int nx = x + dx[nd];
            int ny = y + dy[nd];
            
            if (vis.find({nx, ny}) == vis.end() && robot.move()) {
                Dfs(nx, ny, nd, robot);
                
                // in normal dfs, control flow itself comes back to (x, y) position
                // but here, we have to physically move the robot back to the original cell
                GoBack(robot);
            }
            
            // robot has to physically also change the direction
            // as we are following the clockwise order - so we are moving the robot to the right
            // again software vs hardware implementation concept
            robot.turnRight();
        }
    }
    
    void cleanRoom(Robot& robot) {
        Dfs(0, 0, 0, robot);
    }
};
