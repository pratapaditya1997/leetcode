const int DELTA = 1e4 + 4;
const int N = 2 * DELTA;

int n, t[4*N];

int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (l == tl && r == tr) return t[v];
    
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm))
        + sum(v*2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

void update(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        t[v] += val;
        return;
    }
    
    int tm = (tl + tr) / 2;
    if (pos <= tm) update(v*2, tl, tm, pos, val);
    else update(v*2 + 1, tm + 1, tr, pos, val);
    
    t[v] = t[v*2] + t[v*2 + 1];
}

void init() {
    memset(t, 0, sizeof t);
}

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        init();
        for (int& num: nums) num += DELTA;
        
        int n = nums.size();
        vector<int> ans(n, 0);
        for (int i=n-1; i>=0; i--) {
            update(1, 0, N-1, nums[i], 1);
            ans[i] = sum(1, 0, N-1, 0, nums[i] - 1);
        }
        
        return ans;
    }
};
