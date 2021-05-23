class fenwick {
public:
    int n;
    vector<int> bit;
    
    fenwick(int _n): n(_n) {
        bit.assign(n, 0);
    }
    
    void modify(int x, int v) {
        while (x < n) {
            bit[x] += v;
            x = (x|(x+1));
        }
    }
    
    void modify_range(int l, int r, int v) {
        modify(l, v);
        modify(r + 1, -v);
    }
    
    int get(int x) {
        int ret = 0;
        while (x >= 0) {
            ret += bit[x];
            x = (x&(x+1)) - 1;
        }
        return ret;
    }
    
    int get_range(int l, int r) {
        return get(r) - get(l-1);
    }
};

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        if (s[n-1] != '0') return false;
        
        fenwick f(n + 1);
        f.modify_range(0, 0, 1);
        for (int i=0; i<n; i++) {
            if (s[i] == '0' && f.get(i)) {
                int l = i + minJump;
                int r = min(i + maxJump, n - 1);
                if (l > r) continue;
                if (r == n-1) return true;
                f.modify_range(l, r, 1);
            }
        }
        
        if (f.get(n-1)) return true;
        return false;
    }
};
