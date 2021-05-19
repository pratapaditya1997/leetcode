typedef pair<int, double> pdi;

const int N = 40;

vector<pdi> g[N];

void init() {
    for (int i=0; i<N; i++) {
        g[i].clear();
    }
}

void dfs(int v, int u, vector<vector<double>>& d, vector<int>& vis) {
    vis[v] = 1;
    for (auto& p: g[v]) {
        int to = p.first;
        double mult = p.second;
        
        if (vis[to]) continue;
        double cur = d[u][v] * mult;
        d[u][to] = cur;
        dfs(to, u, d, vis);
    }
}

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& values, vector<vector<string>>& queries) {
        init();
        unordered_map<string, int> m;
        
        int k = 0, n = eq.size();
        for (int i=0; i<n; i++) {
            string u = eq[i][0], v = eq[i][1];
            double w = values[i];
            
            if (m.find(u) == m.end()) m[u] = k++;
            if (m.find(v) == m.end()) m[v] = k++;
            int ui = m[u], vi = m[v];
            
            g[ui].push_back({vi, w});
            g[vi].push_back({ui, (1.0 / w)});
        }
        
        vector<vector<double>> d(k, vector<double>(k, -1.0));
        vector<int> vis(k, 0);
        
        for (int i=0; i<k; i++) d[i][i] = 1.0;
        for (int i=0; i<k; i++) {
            vis.assign(k, 0);
            dfs(i, i, d, vis);
        }
        
        int q = queries.size();
        vector<double> ans(q, -1.0);
        for (int i=0; i<q; i++) {
            string u = queries[i][0], v = queries[i][1];
            if (m.find(u) == m.end() || m.find(v) == m.end()) continue;
            int ui = m[u], vi = m[v];
            if (d[ui][vi] == -1.0) {
                if (d[vi][ui] == -1.0) continue;
                ans[i] = (1.0 / d[vi][ui]);
            } else {
                ans[i] = d[ui][vi];
            }
        }
        
        return ans;
    }
};
