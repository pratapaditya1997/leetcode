const int N = 1e4 + 4;

vector<int> g[N];
vector<int> in_deg, vis;

void init(int n) {
    for (int i=0; i<n; i++) {
        g[i].clear();
    }
    in_deg.assign(n, 0);
    vis.assign(n, 0);
}

class Solution {
public:
    bool sequenceReconstruction(vector<int>& orig, vector<vector<int>>& seqs) {
        int n = orig.size();
        init(n + 1);
        
        for (auto& seq: seqs) {
            if (seq[0] > n || seq[0] <= 0) return false;
            vis[seq[0]] = 1;
            for (int i=0; i<seq.size()-1; i++) {
                int u = seq[i], v = seq[i+1];
                if (u > n || v > n || u <= 0 || v <= 0) return false;
                g[u].push_back(v);
                in_deg[v]++;
                vis[u] = vis[v] = 1;
            }
        }
        
        int present = accumulate(vis.begin(), vis.end(), 0);
        if (present != n) return false;
        
        queue<int> q;
        vector<int> topo_ordering;
        for (int i=1; i<=n; i++) {
            if (in_deg[i] == 0) q.push(i);
        }
    
        while(!q.empty()) {
            if (q.size() != 1) return false;
            int v = q.front(); q.pop();
            topo_ordering.push_back(v);
            
            for (int to: g[v]) {
                in_deg[to]--;
                if (in_deg[to] == 0) q.push(to);
            }
        }
        
        return (topo_ordering == orig);
    }
};
