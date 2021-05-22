class dsu {
public:
    int n;
    vector<int> p, sz;
    
    dsu(int _n): n(_n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        sz.assign(n, 1);
    }
    
    int get(int x) {
        if (x == p[x]) return x;
        return (p[x] = get(p[x]));
    }
    
    void unite(int x, int y) {
        x = get(x);
        y = get(y);
        
        if (x != y) {
            if (sz[x] < sz[y]) swap(x, y);
            sz[x] += sz[y];
            p[y] = x;
        }
    }
};

/*
* divide cell into 4 triangles
* numbering 0 to 3 in order [up, right, bottom, left]
*/

class Solution {
public:
    int regionsBySlashes(vector<string>& g) {
        int n = g.size();
        dsu d(4*n*n);
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                int idx = 4*(i*n + j);
                
                /*
                * internal cell connections
                * the empty cell case will be covered by the combination of both of these
                * below cases
                */
                if (g[i][j] != '\\') {
                    d.unite(idx + 1, idx + 2);
                    d.unite(idx + 0, idx + 3);
                }
                if (g[i][j] != '/') {
                    d.unite(idx + 0, idx + 1);
                    d.unite(idx + 2, idx + 3);
                }
                
                // up - down connections with neighbour cells
                if (i + 1 < n) d.unite(idx + 2, idx + 4*n + 0);
                if (i - 1 > 1) d.unite(idx + 0, idx - 4*n + 2);
                
                // left - right connections with neighbour cells
                if (j + 1 < n) d.unite(idx + 1, idx + 4 + 3);
                if (j - 1 > 1) d.unite(idx + 3, idx - 4 + 1);
            }
        }
        
        int ans = 0;
        for (int idx = 0; idx < 4*n*n; idx++) {
            if (idx == d.p[idx]) ++ans;
        }
        
        return ans;
    }
};
