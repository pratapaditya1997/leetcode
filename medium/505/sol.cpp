typedef pair<int, int> pii;

const int INF = 1e6;

pii d[] = {{0,1}, {0,-1}, {-1,0}, {1,0}};

class Solution {
public:
    int shortestDistance(vector<vector<int>>& g, vector<int>& s, vector<int>& t) {
        int n = g.size(), m = g[0].size();
        vector<vector<int>> dist (n, vector<int>(m, INF));
        
        pii src = {s[0], s[1]}, dest = {t[0], t[1]};
        dist[src.first][src.second] = 0;
        
        queue<pii> q;
        q.push(src);
        
        while (!q.empty()) {
            pii cur = q.front();
            q.pop();
            
            for (int i=0; i<4; ++i) {
                int x = cur.first + d[i].first;
                int y = cur.second + d[i].second;

                int cnt = 0;
                while (x >= 0 && y >= 0 && x < n && y < m && g[x][y] == 0) {
                    x += d[i].first;
                    y += d[i].second;
                    ++cnt;
                }
                x -= d[i].first;
                y -= d[i].second;
                if (dist[cur.first][cur.second] + cnt < dist[x][y]) {
                    dist[x][y] = dist[cur.first][cur.second] + cnt;
                    pii nxt = {x, y};
                    q.push(nxt);
                }
            }
        }
        
        if (dist[dest.first][dest.second] == INF) return -1;
        return dist[dest.first][dest.second];
    }
};
