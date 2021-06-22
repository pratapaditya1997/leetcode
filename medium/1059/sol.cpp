vector<vector<int>> g;
vector<int> od, col;

enum color {WHITE, GRAY, BLACK};

bool IsCyclic (int v) {
    col[v] = GRAY;
    
    for (int to: g[v]) {
        if (col[to] == GRAY) return true;
        if (col[to] == WHITE && IsCyclic(to)) return true;
    }
    
    col[v] = BLACK;
    return false;
}

class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int src, int dest) {
        g = vector<vector<int>> (n, vector<int>());
        od = vector<int>(n, 0);
        col = vector<int>(n, WHITE);
        
        for (auto& edge: edges) {
            int u = edge[0], v = edge[1];
            g[u].push_back(v);
            ++od[u];
        }
        
        if (IsCyclic(src)) return false;
        
        set<int> s;
        for (int i=0; i<n; ++i) {
            if (col[i] == BLACK && od[i] == 0) s.insert(i);
        }
        
        return (s.size() == 1 && *s.begin() == dest);
    }
};
