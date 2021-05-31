typedef pair<int, int> pii;

pii d[] = {{-1,0}, {0,1}, {1,0}, {0,-1}};

class Solution {
public:
    int n, m;
    vector<vector<int>> vis;
    
    void dfs(int x, int y, int threshold, vector<vector<int>>& h) {
        vis[x][y] = 1;
        for (int i=0; i<4; ++i) {
            int nx = x + d[i].first;
            int ny = y + d[i].second;
            if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                if (!vis[nx][ny] && abs(h[nx][ny] - h[x][y]) <= threshold) {
                    dfs(nx, ny, threshold, h);
                }
            }
        }
    }
    
    int minimumEffortPath(vector<vector<int>>& h) {
        n = h.size();
        m = h[0].size();
        
        vis = vector<vector<int>>(n, vector<int>(m, 0));
        
        auto check = [&](int k) {
            for (auto& v: vis) {
                fill(v.begin(), v.end(), 0);
            }
            dfs(0, 0, k, h);
            return vis[n-1][m-1];
        };
        
        int l = 0, r = 1e6 + 6, ans;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (check(mid)) {
                ans = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        
        return ans;
    }
};
