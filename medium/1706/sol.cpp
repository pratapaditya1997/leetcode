class Solution {
public:
    vector<int> findBall(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        vector<int> ans(m, -1);
        
        function<void(int,int,int&)> dfs = [&](int x, int y, int& end_at) {
            if (x == n) {
                end_at = y;
                return;
            }
            if (g[x][y] == 1 && y<m-1 && g[x][y+1] == 1) dfs(x + 1, y + 1, end_at);
            if (g[x][y] == -1 && y>0 && g[x][y-1] == -1) dfs(x + 1, y - 1, end_at);
        };
        
        for (int ball = 0; ball < m; ball++) {
            int end_at = -1;
            dfs(0, ball, end_at);
            if (end_at != -1) ans[ball] = end_at;
        }
        
        return ans;
    }
};
