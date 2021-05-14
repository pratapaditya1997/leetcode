typedef pair<int, int> pii;

const int N = 105;

vector<pii> g[N];
vector<int> d;

void dijk(int source) {
    d[source] = 0;
    set<pii> s;
    s.insert({0, source});
    
    while(!s.empty()) {
        int v = s.begin()->second;
        s.erase(s.begin());
        
        for (auto edge: g[v]) {
            int to = edge.first;
            int len = edge.second;
            
            if (d[v] + len < d[to]) {
                s.erase({d[to], to});
                d[to] = d[v] + len;
                s.insert({d[to], to});
            }
        }
    }
}

void init() {
    for (int i=0; i<N; i++) g[i].clear();
}

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& edges, int n, int s) {
        init();
        for (auto& edge: edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            g[u].push_back({v, w});
        }
        d.assign(n + 1, INT_MAX);
        dijk(s);
        
        int ans = 0;
        for (int i=1; i<=n; i++) {
            if (d[i] >= INT_MAX) return -1;
            ans = max(ans, d[i]);
        }
        return ans;
    }
};
