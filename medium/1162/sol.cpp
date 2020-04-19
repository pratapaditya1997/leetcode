class Solution {
public:
    vector<int> dx{-1,0,1,0};
    vector<int> dy{0,1,0,-1};
    
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = -1;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        queue<pair<int,int>> q;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]) q.push({i,j});
            }
        }
        
        auto valid = [&](pair<int,int> p) {
            return (p.first >= 0 && p.first < n && p.second >= 0 && p.second < m && !grid[p.first][p.second] && !vis[p.first][p.second]);
        };
        
        while(!q.empty()) {
            pair<int,int> cur, next; 
            cur = q.front(); q.pop();
            for(int i=0; i<4; i++) {
                next.first = cur.first + dx[i];
                next.second = cur.second + dy[i];
                if(valid(next)) {
                    q.push(next);
                    vis[next.first][next.second] = vis[cur.first][cur.second] + 1;
                    ans = max(ans, vis[next.first][next.second]);
                }
            }
        }
        
        return ans;
    }
};
