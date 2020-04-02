class Solution {
public:
    vector<int> dx{0,1,0,-1};
    vector<int> dy{1,0,-1,0};
    
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        if(n == 0) return vector<int>{};
        int m = mat[0].size();
        vector<vector<bool>> seen(n, vector<bool>(m,0));
        
        int curX=0, curY=0, dir=0;
        vector<int> order;
        for(int i=0; i<n*m; i++) {
            order.push_back(mat[curX][curY]);
            seen[curX][curY] = 1;
            int nextX = curX + dx[dir];
            int nextY = curY + dy[dir];
            if(nextX >=0 && nextX < n && nextY >=0 && nextY < m && !seen[nextX][nextY]) {
                curX = nextX;
                curY = nextY;
            } else {
                dir = (dir+1) % 4;
                curX = curX + dx[dir];
                curY = curY + dy[dir];
            }
        }
        
        return order;
    }
};
