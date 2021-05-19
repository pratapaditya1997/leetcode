typedef pair<int,int> pii;

class dsu {
public:
    vector<int> p, sz;
    int n;
    
    dsu(int _n): n(_n) {
        p.resize(n);
        sz.assign(n, 1);
        iota(p.begin(), p.end(), 0);
    }
    
    int get(int x) {
        return (x == p[x] ? x : (p[x] = get(p[x])));
    }
    
    void unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x != y) {
            if (sz[x] < sz[y]) swap(x, y);
            p[y] = x;
            sz[x] += sz[y];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        
        dsu d(n);
        for (int i=0; i<n; i++) {
            pii pi = {stones[i][0], stones[i][1]};
            for (int j=0; j<i; j++) {
                pii pj = {stones[j][0], stones[j][1]};
                if (pi.first == pj.first || pi.second == pj.second) {
                    d.unite(i, j);
                }
            }
        }
        
        int ans = 0;
        for (int i=0; i<n; i++) {
            if (i == d.get(i)) {
                ans += (d.sz[i] - 1);
            }
        }
        
        return ans;
    }
};
