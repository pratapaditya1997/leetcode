const int N = 1e5 + 5;

vector<bool> is_prime(N, true);
vector<int> sp(N, -1);

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
            p[y] = x;
            sz[x] += sz[y];
        }
    }
};

void compute_primes() {
    is_prime[0] = is_prime[1] = false;
    for (int i=2; i*i<N; i++) {
        if (is_prime[i]) {
            sp[i] = i;
            for (int j=i*i; j<N; j+=i) {
                is_prime[j] = false;
                sp[j] = i;
            }
        }
    }
}

void compute_factors(int n, vector<int>& pf) {
    while(n > 1) {
        if (sp[n] == -1) sp[n] = n;
        pf.push_back(sp[n]);
        n /= sp[n];
    }
}

class Solution {
public:
    int largestComponentSize(vector<int>& a) {
        if (is_prime[1]) compute_primes();
        
        dsu d(N);
        unordered_map<int, vector<int>> m;
        vector<int> pf;
        
        for (int num: a) {
            pf.clear();
            compute_factors(num, pf);
            for (int factor: pf) {
                if (m.find(factor) == m.end()) m[factor] = {};
                m[factor].push_back(num);
            }
        }
        
        for (auto& p: m) {
            int sz = p.second.size();
            for (int i=0; i<sz-1; i++) {
                d.unite(p.second[i], p.second[i+1]);
            }
        }
        
        int ans = 1;
        for (int num: a) {
            if (num == d.p[num]) ans = max(ans, d.sz[num]);
        }
        return ans;
    }
};
