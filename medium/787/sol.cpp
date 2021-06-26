const int INF = 1e7;

vector<vector<int>> d;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& edges, int src, int dest, int k) {
        d = vector<vector<int>> (n, vector<int>(n+2, INF));
        
        d[src][0] = 0;
        
        for (int s=1; s<=k+1; ++s) {
            for (auto edge: edges) {
                int u = edge[0], v = edge[1], w = edge[2];
                if (d[u][s-1] >= INF) continue;
                d[v][s] = min(d[v][s], d[u][s-1] + w);
            }
        }
        
        int ans = INF;
        for (int i=0; i<=k+1; ++i) {
            ans = min(ans, d[dest][i]);
        }
        
        if (ans == INF) return -1;
        return ans;
    }
};
