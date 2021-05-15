typedef pair<int,int> pii;

class dsu {
    public:
    vector<int> p, sz;
    int n;

    dsu(int _n) : n(_n) {
        p.resize(n);
        sz.resize(n);
        iota(p.begin(), p.end(), 0);
        fill(sz.begin(), sz.end(), 1);
    }

    inline int get(int x) {
        return (x == p[x] ? x : (p[x] = get(p[x])));
    }

    inline bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if(x != y) {
            if (sz[x] < sz[y]) {
                swap(x, y);
            }
            p[y] = x;
            sz[x] += sz[y];
            return true;
        }
        return false;
    }
};

class Solution {
public:
    void calculate_next_greater(vector<int>& ng, vector<double>& t) {
        int n = ng.size();
        vector<int> stk(n);
        
        for (int i=0; i<n; i++) {
            while(!stk.empty() && t[stk.back()] <= t[i]) {
                ng[stk.back()] = i;
                stk.pop_back();
            }
            stk.push_back(i);
        }
        while(!stk.empty()) {
            ng[stk.back()] = -1;
            stk.pop_back();
        }
    }
    
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pii> v(n);
        
        for (int i=0; i<n; i++) {
            v[i] = {position[i], speed[i]};
        }
        sort(v.begin(), v.end());
        
        vector<double> t(n);
        for (int i=0; i<n; i++) {
            t[i] = ((target - v[i].first) / (double)v[i].second);
        }
        
        vector<int> ng(n);
        calculate_next_greater(ng, t);
        
        dsu d(n);
        for (int i=0; i<n; i++) {
            if (ng[i] == -1) continue;
            d.unite(i, ng[i]);
        }
        
        set<int> ans;
        for (int i=0; i<n; i++) ans.insert(d.get(i));
        return ans.size();
    }
};
