int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

bool valid(int x, int y, int n, int m) {
    return (x >= 0 && y >= 0 && x < n && y < m);
}

class dsu {
public:
    int n, count = 0;
    vector<int> p, sz;
    
    dsu(int _n): n(_n) {
        p.assign(n, -1);
        sz.assign(n, 1);
    }
    
    int get(int x) {
        if (x == p[x]) return x;
        return (p[x] = get(p[x]));
    }
    
    void setActive(int x) {
        if (p[x] == -1) {
            p[x] = x;
            ++count;
        }
    }
    
    bool isValid(int x) {
        return p[x] != -1;
    }
    
    void unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x != y) {
            if (sz[x] < sz[y]) swap(x, y);
            p[y] = x;
            sz[x] += sz[y];
            --count;
        }
    }
};

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        dsu d(m * n);
        
        vector<int> ans;
        for (auto& pos: positions) {
            int x = pos[0], y = pos[1];
            int idx = x*n + y;
            d.setActive(idx);
            for (int i=0; i<4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                int nxtIdx = nx*n + ny;
                if (valid(nx, ny, m, n) && d.isValid(nxtIdx)) {
                    d.unite(idx, nxtIdx);
                }
            }
            ans.push_back(d.count);
        }
        
        return ans;
    }
};
