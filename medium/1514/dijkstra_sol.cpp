typedef pair<double, int> pdi;

const int N = 1e4 + 4;

vector<pdi> g[N];
vector<double> d;

void dijk(int source) {
    d[source] = 1.0;
    set<pdi> s;
    s.insert({-1.0, source});
    
    while(!s.empty()) {
        int v = s.begin()->second;
        s.erase(s.begin());
        
        for (auto edge: g[v]) {
            int to = edge.second;
            double prob = edge.first;
            
            if (d[v] * prob > d[to]) {
                s.erase({-1.0 * d[to], to});
                d[to] = d[v] * prob;
                s.insert({-1.0 * d[to], to});
            }
        }
    }
}

void init() {
    for (int i=0; i<N; i++) g[i].clear();
}

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        init();
        int m = edges.size();
        for (int i=0; i<m; i++) {
            int u = edges[i][0], v = edges[i][1];
            double w = succProb[i];
            g[u].push_back({w, v});
            g[v].push_back({w, u});
        }
        
        d.assign(n, 0.0);
        dijk(start);
        
        return d[end];
    }
};
