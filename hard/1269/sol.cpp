typedef long long int ll;

const ll MOD = 1e9 + 7;

inline void Add(ll& x, ll y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

class Solution {
public:
    int n;
    vector<vector<ll>> dp;
    
    int f(int i, int moves) {
        if (i < 0 || i >=n) return 0;
        if (moves == 0 && i == 0) return 1;
        if (moves == 0) return 0;
        
        if (dp[i][moves] != -1) return dp[i][moves];
        ll ret = 0;
        Add(ret, f(i+1, moves-1));
        Add(ret, f(i-1, moves-1));
        Add(ret, f(i, moves-1));
        return dp[i][moves] = ret;;
    }
    
    int numWays(int moves, int _n) {
        n = min(moves, _n);
        dp = vector<vector<ll>> (n, vector<ll>(moves + 1, -1));
        return f(0, moves);
    }
};
